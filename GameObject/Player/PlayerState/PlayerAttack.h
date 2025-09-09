#pragma once
#include"../Player.h"
#include"IPlayerState.h"
#include"PlayerNone.h"

class PlayerAttack :public IPlayerState{
public:
  PlayerAttack() {};
  ~PlayerAttack() {};

  void Init([[maybe_unused]] Player *ins) override;

  void Update(Player *ins) override;

private:

	float time_ = 0.0f;

	float timerMax_ = 0.5f;

};