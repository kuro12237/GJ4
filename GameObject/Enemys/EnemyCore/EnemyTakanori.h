#pragma once
#include "../EnemyBase.h"

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

private:
};
