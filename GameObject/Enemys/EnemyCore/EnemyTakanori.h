#pragma once
#include "../EnemyBase.h"
#include"EnemyState/EnemyNoneState.h"
#include"EnemyState/EnemyMoveState.h"


class EnemyTakanori : public EnemyBase {
public:
  EnemyTakanori() {};
  ~EnemyTakanori() {};

  void Init() override;

  void Update() override;

  /// <summary>
  /// 衝突時コールバック
  /// </summary>
  void OnCollision(std::weak_ptr<ObjectComponent> other) override;

  void ChangeScene(std::unique_ptr<IEnemyState> state);

private:

	std::unique_ptr<IEnemyState> state_ = nullptr;

};
