#pragma once
#include"CLEYERA/CLEYERA.h"


/// <summary>
/// プレイヤー
/// </summary>
class Player :public CLEYERA::Component::ObjectComponent{
public:
  Player() {};
  ~Player() {};

  void Init() override;
  void Update() override;

private:
};



