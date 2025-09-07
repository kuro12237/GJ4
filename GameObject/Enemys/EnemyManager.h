#pragma once
#include "EnemyCore/EnemyTakanori.h"

#include"HitEffect/HitEffect.h"

class EnemyManager {
public:
  EnemyManager() {};
  ~EnemyManager() {};

  void Init();

  void Update();

  void SpawnEnemy(const Math::Vector::Vec3 &pos);

  void SpawnEffect(const Math::Vector::Vec3 &pos);

private:
  std::list<std::weak_ptr<EnemyBase>> enemies_;
  std::list<std::weak_ptr<HitEnemyEffect>> effects_;
};
