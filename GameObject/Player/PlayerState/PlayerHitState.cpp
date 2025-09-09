#include "PlayerHitState.h"

void PlayerHitState::Init([[maybe_unused]] Player *ins) {}

void PlayerHitState::Update(Player *ins) {

  time_ += 1.0f / 60.0f;

  if (time_ >= timerMax_) {
    ins->ChangeState(std::make_unique<PlayerNone>());
    return;
  }
}
