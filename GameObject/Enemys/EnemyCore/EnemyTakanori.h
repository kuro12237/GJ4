#pragma once
#include "../EnemyBase.h"
#include "EnemyState/EnemyMoveState.h"
#include "EnemyState/EnemyNoneState.h"

#include "../../Util/Random/RandomGenerator.h"
#include "../../WorldSpeed/WorldSpeed.h"
#include "EnemyState/EnemyHitState.h"

#include "Bullet/EnemyBullet.h"
#include"../../Paramerter/ParamBase.h"

class EnemyTakanori : public EnemyBase{
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

  void SetIsWorldSpeed(bool f) { isWorldSpeed_ = f; }
  void SetWorldSetting(std::weak_ptr<WorldSetting> w) { world_ = w; }

  void AttackBullet(const Math::Vector::Vec3 &pos,
                    const Math::Vector::Vec3 &velo = {0.0f,0.0f,-0.1f});

private:

    
Math::Vector::Vec4 CalcColor(float x);

  std::unique_ptr<IEnemyState> state_ = nullptr;

  std::weak_ptr<WorldSetting> world_;
  float zInterval_ = 0.0f;
  bool isWorldSpeed_ = false;
  bool isWorldSpeedLock_ = false;

  std::list<std::weak_ptr<EnemyBullet>> bullets_;
};
