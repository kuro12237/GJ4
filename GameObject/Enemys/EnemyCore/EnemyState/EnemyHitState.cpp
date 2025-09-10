#include "EnemyHitState.h"

void EnemyHitState::Init(EnemyTakanori *ins) {

  auto modelManager = CLEYERA::Manager::ModelManager::GetInstance();
  uint32_t modelHandle = modelManager->LoadModel(
      "Resources/Model/Enemy/damageEnemy", "damageEnemy");
  ins->SetModelHandle(modelHandle);
}

void EnemyHitState::Update(EnemyTakanori *ins) {

  timer_ += 1.0f / 60.0f;

  if (timer_ >= timerMax_) {

    ins->ChangeScene(std::make_unique<EnemyMoveState>());
  }
}
