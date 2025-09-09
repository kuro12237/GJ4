#include "EnemyMoveState.h"

void EnemyMoveState::Init(EnemyTakanori *ins) {}

void EnemyMoveState::Update(EnemyTakanori *ins) {

  if (this->translate_->x >= widthMinMax_||this->translate_->x <= -widthMinMax_) {

    speed_ *= -1.0f;
  }

  translate_->x += speed_;

}
