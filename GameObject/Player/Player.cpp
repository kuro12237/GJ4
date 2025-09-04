#include "Player.h"

void Player::Init() {

  this->category_ = VAR_NAME(Player_NudeHuman);
  uint32_t modelHandle =
      modelManager_->LoadModel("Resources/Model/Player/Human_Nude", "Human_Nude");
  this->SetModelHandle(modelHandle);
}

void Player::Update() {}
