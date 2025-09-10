#include "EnemyDeadState.h"

void EnemyDeadState::Init(EnemyTakanori *ins) {}

void EnemyDeadState::Update(EnemyTakanori *ins) {

  timer_ += 1.0f / 60.0f;

  if (timer_ >= timerMax_) {
    isDead_ = true;
  }
}
