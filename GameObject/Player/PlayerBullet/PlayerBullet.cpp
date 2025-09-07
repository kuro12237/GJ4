#include "PlayerBullet.h"

void PlayerBullet::Init() {

  this->category_ = VAR_NAME(PlayerBullet);
  uint32_t modelHandle =
      modelManager_->LoadModel("Resources/Model/Player/Bullet", "Bullet");
  this->SetModelHandle(modelHandle);
  this->gameObject_->SetLayerNumber(0);

}

void PlayerBullet::Update() { translate_.z += 0.1f; }
