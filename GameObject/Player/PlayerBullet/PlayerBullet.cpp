#include "PlayerBullet.h"

void PlayerBullet::Init() {

  this->category_ = VAR_NAME(PlayerBullet);
  uint32_t modelHandle =
      modelManager_->LoadModel("Resources/Model/Player/Bullet", "Bullet");
  this->SetModelHandle(modelHandle);
  this->gameObject_->SetLayerNumber(0);
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
