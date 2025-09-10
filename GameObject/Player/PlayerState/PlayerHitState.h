#pragma once
#include "IPlayerState.h"
#include"PlayerNone.h"

class PlayerHitState : public IPlayerState {
public:
  PlayerHitState() {};
  ~PlayerHitState() {};

  void Init([[maybe_unused]] Player *ins) override;

  void Update(Player *ins) override;

private:

		float time_ = 0.0f;

  float timerMax_ = 0.4f;
};