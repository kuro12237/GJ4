#pragma once
#include"IPlayerState.h"


class PlayerNone :public IPlayerState{
public:
  PlayerNone() {};
  ~PlayerNone() {};

  void Init() override {};

  void Update([[maybe_unused]] Player *ins) override { this->Control(); };

private:



};
