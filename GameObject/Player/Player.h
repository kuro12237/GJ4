#pragma once
#include "CLEYERA.h"
#include"../Paramerter/ParamBase.h"

#include"PlayerState/PlayerAttack.h"
#include"PlayerState/PlayerNone.h"

#include"PlayerState/PlayerHitState.h"

class PlayerBullet;
/// <summary>
/// プレイヤー
/// </summary>
class Player : public CLEYERA::Component::ObjectComponent ,public ParamBase{
public:
  Player() {};
  ~Player() {};

  void Init() override;
  void Update() override;

  void ImGuiUpdate() override;
  #pragma region Get

  float &GetZCenter() { return zCenter_; }

#pragma endregion

  void ChangeState(std::unique_ptr<IPlayerState> state);

    /// <summary>
  /// 衝突時コールバック
  /// </summary>
  void OnCollision(std::weak_ptr<ObjectComponent> other);

private:

  float widthMinMax_ = 9.0f;
  float heightMinMax_ = 3.0f;

  float speed_ = 0.0f;

  float zCenter_ = 0.0f;

  std::unique_ptr<IPlayerState> state_ = nullptr;

};
