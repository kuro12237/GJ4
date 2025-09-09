#pragma once
#include"IPlayerState.h"

#include"../Player.h"
class PlayerNone :public IPlayerState{
public:
  PlayerNone() {};
  ~PlayerNone() {};

  void Init([[maybe_unused]] Player *ins) override;

  void Update([[maybe_unused]] Player *ins) override;

private:



};
