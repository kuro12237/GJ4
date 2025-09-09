#include "PlayerBullet.h"

void PlayerBullet::Init() {

  this->category_ = VAR_NAME(PlayerBullet);
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

  scale_ = {0.5f, 0.5f, 0.5f};
}

void PlayerBullet::Update() {
  translate_.z += 0.1f;
  TimeFunc();
}

void PlayerBullet::TimeFunc() {

  time_ += 1.0f / 60.0f;

  if (time_ >= timeMax_) {
    isDead_ = true;

    SetMode(OBJ_MODE::REMOVE);
  }
}

void PlayerBullet::OnCollision(
    [[maybe_unused]] std::weak_ptr<CLEYERA::Component::ObjectComponent> other) {

  auto it = other.lock();

  if (std::dynamic_pointer_cast<PlayerBullet>(it)) {
    return;
  }
  if (it->GetCategory() == "Player") {
    return;
  }
    isDead_ = true;

  SetMode(OBJ_MODE::REMOVE);
}