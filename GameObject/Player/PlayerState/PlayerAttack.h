#pragma once
#include"../Player.h"
#include"IPlayerState.h"

class PlayerAttack :public IPlayerState{
public:
  PlayerAttack() {};
  ~PlayerAttack() {};

  void Init() override;

  void Update(Player *ins) override;

private:
};