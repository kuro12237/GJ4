#pragma once
#include "IPlayerState.h"

class PlayerHitState : public IPlayerState {
public:
  PlayerHitState() {};
  ~PlayerHitState() {};

  void Init() override;

  void Update(Player *ins) override;

private:
};