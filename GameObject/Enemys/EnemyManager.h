#pragma once
#include "EnemyCore/EnemyTakanori.h"

class EnemyManager {
public:
  EnemyManager() {};
  ~EnemyManager() {};

  void Init();

  void Update();

  void SpownEnemy(const Math::Vector::Vec3 &pos);

private:
  std::list<std::weak_ptr<EnemyBase>> enemies_;
};
