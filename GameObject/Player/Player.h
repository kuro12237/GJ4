#pragma once
#include "CLEYERA/CLEYERA.h"
#include"../Paramerter/ParamBase.h"

/// <summary>
/// プレイヤー
/// </summary>
class Player : public CLEYERA::Component::ObjectComponent ,public ParamBase{
public:
  Player() {};
  ~Player() {};

  void Init() override;
  void Update() override;

  #pragma region Get

  float &GetZCenter() { return zCenter_; }

#pragma endregion


private:
  void Control();

  float widthMinMax_ = 9.0f;
  float heightMinMax_ = 3.0f;

  float speed_ = 0.0f;

  float zCenter_ = 0.0f;
};
