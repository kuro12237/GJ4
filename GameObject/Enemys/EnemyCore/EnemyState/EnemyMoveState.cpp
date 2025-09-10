#include "EnemyMoveState.h"

void EnemyMoveState::Init(EnemyTakanori *ins) {

    auto modelManager = CLEYERA::Manager::ModelManager::GetInstance();
  uint32_t modelHandle = modelManager->LoadModel(
      "Resources/Model/Enemy/normalEnemy", "normalEnemy");
  ins->SetModelHandle(modelHandle);
}

void EnemyMoveState::Update(EnemyTakanori *ins) {

  if (this->translate_->x >= widthMinMax_ ||
      this->translate_->x <= -widthMinMax_) {

    speed_ *= -1.0f;
  }

  translate_->x += speed_;

  attackTimer_ += 1.0f / 60.0f;
  if (attackTimer_ >= attackTimerMax_) {
    ins->AttackBullet(*translate_, {0.0f,0.0f,-0.2f});
    attackTimer_ = 0.0f;
  }
}
