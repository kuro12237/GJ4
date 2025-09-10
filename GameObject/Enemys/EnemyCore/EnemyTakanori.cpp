#include "EnemyTakanori.h"

using namespace CLEYERA::Component;

void EnemyTakanori::Init() {

  this->category_ = VAR_NAME(EnemyTakanori);
  this->CreateJsonSystem("Resources/Configs/Entitiys/EnemyTakanori/");

  uint32_t modelHandle = modelManager_->LoadModel(
      "Resources/Model/Enemy/normalEnemy", "normalEnemy");
  this->SetModelHandle(modelHandle);

  auto json = CLEYERA::Manager::GlobalVariables::GetInstance();
  json->SaveFile(name_);
  translate_.y = 4.0f;

  // コライダー作成
  ObjectComponent::CreateCollider(ColliderType::AABB);
  // 当たり判定関数セット
  collider_->SetHitCallFunc([this](std::weak_ptr<ObjectComponent> other) {
    this->OnCollision(other);
  });

  auto aabb = std::dynamic_pointer_cast<CLEYERA::Util::Collider::AABBCollider>(
      GetCollider().lock());
  aabb->GetAABB_().max = {1.0f, 1.0f, 1.0f};
  aabb->GetAABB_().min = {-1.0f, -1.0f, -1.0f};

  this->ChangeScene(std::make_unique<EnemyMoveState>());

  zInterval_ = RandomGenerator::GetFloat(5.0f, 8.0f);
  scale_ = {0.75f, 0.75f, 1.0f};
}

void EnemyTakanori::Update() {

  bullets_.remove_if([](const std::weak_ptr<EnemyBullet> &b) {
    if (!b.lock()) {
      return true;
    }
    return b.lock()->GetIsDead();
  });

  if (state_) {
    state_->Update(this);
  }

  auto playerToEPos = (translate_.z - zInterval_) - playerPos_->z;

  if (playerToEPos <= 0.0f) {
    this->isWorldSpeed_ = true;
  }
  if (isWorldSpeed_) {
    world_.lock()->CalcSpeed(translate_);
  }

  gameObject_->ColorData().color_ = this->CalcColor(temperature_);

  isDead_ = CalcTemperature(translate_);
  if (isDead_) {
    SetMode(OBJ_MODE::REMOVE);
  }
}

void EnemyTakanori::OnCollision(
    [[maybe_unused]] std::weak_ptr<ObjectComponent> other) {
  auto it = other.lock();

  if (it->GetCategory() == "EnemyTakanori") {
    return;
  }
  if (it->GetCategory() == "Player") {
    return;
  }
  if (it->GetCategory() == "EnemyBullet") {
    return;
  }
  this->effectSpawn_(translate_);
  ChangeScene(std::make_unique<EnemyHitState>());

  // SetMode(CLEYERA::Component::ObjectComponent::OBJ_MODE::REMOVE);
}

void EnemyTakanori::ChangeScene(std::unique_ptr<IEnemyState> state) {

  state_ = std::move(state);
  state_->SetPos(&this->translate_);
  state_->SetZInterval(&this->zInterval_);
  state_->SetPlayerPos(this->playerPos_);
  state_->Init(this);
}

void EnemyTakanori::AttackBullet(const Math::Vector::Vec3 &pos,
                                 const Math::Vector::Vec3 &velo) {
  auto objManager = CLEYERA::Manager::ObjectManager::GetInstance();

  std::weak_ptr<EnemyBullet> b = objManager->CreateObject<EnemyBullet>(
      VAR_NAME(EnemyBullet), std::make_shared<EnemyBullet>());

  b.lock()->SetSpownPos(pos);
  b.lock()->SetWorldSetting(world_);
  b.lock()->SetVelo(velo);
  this->bullets_.push_back(b);
}

Math::Vector::Vec4 EnemyTakanori::CalcColor(float x) {
  // 範囲制限
  x = std::clamp(x, -1.0f, 1.0f);

  Math::Vector::Vec4 blue = {27.0f / 255.0f, 50.0f / 255.0f, 183.0f / 255.0f,
                             1.0f};
  Math::Vector::Vec4 white = {1.0f, 1.0f, 1.0f, 1.0f};
  Math::Vector::Vec4 red = {236.0f / 255.0f, 22.0f / 255.0f, 22.0f / 255.0f,
                            1.0f};

  if (x <= 0.0f) {
    // [-1,0] → [0,1] に正規化
    float t = (x + 1.0f) / 1.0f;
    Math::Vector::Vec4 result = {
        Math::Vector::Func::Lerp<float>(blue.x, white.x, t),
        Math::Vector::Func::Lerp<float>(blue.y, white.y, t),
        Math::Vector::Func::Lerp<float>(blue.z, white.z, t),
        Math::Vector::Func::Lerp<float>(blue.w, white.w, t)};

    return result;
  } else {
    // [0,1] → [0,1] に正規化
    float t = x / 1.0f;
    Math::Vector::Vec4 result = {
        Math::Vector::Func::Lerp<float>(white.x, red.x, t),
        Math::Vector::Func::Lerp<float>(white.y, red.y, t),
        Math::Vector::Func::Lerp<float>(white.z, red.z, t),
        Math::Vector::Func::Lerp<float>(white.w, red.w, t)};

    return result;
  }
}
