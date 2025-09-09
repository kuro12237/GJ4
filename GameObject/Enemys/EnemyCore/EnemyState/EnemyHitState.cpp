#include "EnemyHitState.h"

void EnemyHitState::Init(EnemyTakanori *ins) {}

void EnemyHitState::Update(EnemyTakanori *ins) {

timer_ += 1.0f / 60.0f;

if (timer_ >=timerMax_) {

	ins->ChangeScene(std::make_unique<EnemyMoveState>());
}

}
