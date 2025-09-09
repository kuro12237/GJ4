#include "EnemyBullet.h"

void EnemyBullet::Init() {

this->category_ = VAR_NAME(EnemyBullet);
  uint32_t modelHandle =
      modelManager_->LoadModel("Resources/Model/Player/ductTape", "ductTape");
  this->SetModelHandle(modelHandle);
  this->gameObject_->SetLayerNumber(0);
  // コライダー作成
  ObjectComponent::CreateCollider(ColliderType::AABB);
  // 当たり判定関数セット
  collider_->SetHitCallFunc([this](std::weak_ptr<ObjectComponent> other) {
    this->OnCollision(other);
  });
}

void EnemyBullet::Update() {

    translate_+= velo_;

    TimeFunc();

    world_.lock()->CalcSpeed(translate_);
}

void EnemyBullet::OnCollision(std::weak_ptr<ObjectComponent> other) {

  auto it = other.lock();

  if (it->GetCategory() == "EnemyTakanori") {
    return;
  }
  isDead_ = true;

  SetMode(OBJ_MODE::REMOVE);

}

void EnemyBullet::TimeFunc() {
  time_ += 1.0f / 60.0f;

  if (time_ >= timeMax_) {
    isDead_ = true;

    SetMode(OBJ_MODE::REMOVE);
  }
}
