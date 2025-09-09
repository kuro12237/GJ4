#include "PlayerHitState.h"

void PlayerHitState::Init([[maybe_unused]] Player *ins) {

 auto modelManager = CLEYERA::Manager::ModelManager::GetInstance();
  uint32_t modelHandle = modelManager->LoadModel(
      "Resources/Model/Player/damage", "damage");
  ins->SetModelHandle(modelHandle);

}

void PlayerHitState::Update(Player *ins) {

  time_ += 1.0f / 60.0f;

  if (time_ >= timerMax_) {
    ins->ChangeState(std::make_unique<PlayerNone>());
    return;
  }
}
