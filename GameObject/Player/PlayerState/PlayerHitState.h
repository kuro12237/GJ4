#pragma once
#include "IPlayerState.h"

class PlayerHitState : public IPlayerState {
public:
  PlayerHitState() {};
  ~PlayerHitState() {};

  void Init([[maybe_unused]] Player *ins) override;

  void Update(Player *ins) override;

private:
};