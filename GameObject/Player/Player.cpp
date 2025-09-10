#include "Player.h"

void Player::Init() {

  this->category_ = VAR_NAME(Player);
  uint32_t modelHandle =
      modelManager_->LoadModel("Resources/Model/Player/normal", "normal");
  this->SetModelHandle(modelHandle);

  CreateJsonSystem("Resources/Configs/Entitiys/Player/");

  this->SetValue<Math::Vector::Vec3>("translate", translate_);
  translate_ = this->GetValue<Math::Vector::Vec3>("translate");

  this->SetValue<float>("speed", speed_);
  speed_ = this->GetValue<float>("speed");

  this->SetValue<float>("temperatureSpeed", temperatureSpeed_);
  temperatureSpeed_ = this->GetValue<float>("temperatureSpeed");

  auto json = CLEYERA::Manager::GlobalVariables::GetInstance();
  json->SaveFile(name_);

  this->isGravity_ = false;
  this->isTerrainHit_ = false;

  mass_ = 0.5f;
  zCenter_ = translate_.z;
  gameObject_->SetLayerNumber(1);

  this->CreateCollider(ColliderType::AABB);

  collider_->SetHitCallFunc([this](std::weak_ptr<ObjectComponent> other) {
    this->OnCollision(other);
  });

  this->ChangeState(std::make_unique<PlayerNone>());
  scale_ = {1.0f, 1.0f, 1.0f};
}

void Player::Update() {

#ifdef _DEBUG

  this->ImGuiUpdate();

#endif // _DEBUG

  ParamBase::CalcTemperature(translate_);

  if (state_) {
    state_->Update(this);
  }

  TransformUpdate();
}

void Player::ImGuiUpdate() {

  if (name_ == "") {
    return;
  }

  if (ImGui::TreeNode(name_.c_str())) {

    BaseParamImGuiDisply();
    ImGui::SliderFloat("temperatureSpeed", &temperatureSpeed_, 0.0f, 0.1f);
    ImGui::TreePop();
  }
}

void Player::ChangeState(std::unique_ptr<IPlayerState> state) {

  state_ = std::move(state);
  state_->SetForce(&force_);
  state_->SetPosition(&translate_);
  state_->SetZCenter(&zCenter_);
  state_->SetSpeed(&speed_);
  state_->Init(this);
}

void Player::OnCollision(std::weak_ptr<ObjectComponent> other) {

  auto it = other.lock();

  if (it->GetCategory() == "PlayerBullet") {
    return;
  }
  if (it->GetCategory() == "EnemyTakanori") {
    return;
  }
  if (it->GetCategory() == "EnemyBullet") {

    this->ChangeState(std::make_unique<PlayerHitState>());
  }
}
