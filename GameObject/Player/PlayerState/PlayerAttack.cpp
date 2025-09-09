#include "PlayerAttack.h"

void PlayerAttack::Init([[maybe_unused]] Player *ins) {

  auto modelManager = CLEYERA::Manager::ModelManager::GetInstance();
  uint32_t modelHandle =
      modelManager->LoadModel("Resources/Model/Player/bulletmotion", "bulletmotion");
  ins->SetModelHandle(modelHandle);
}

void PlayerAttack::Update(Player *ins) {

  this->Control();

  time_ += 1.0f / 60.0f;

  if (time_ >= timerMax_) {
    ins->ChangeState(std::make_unique<PlayerNone>());
    return;
  }
}
