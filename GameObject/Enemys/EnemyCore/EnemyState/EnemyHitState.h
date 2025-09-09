#pragma once
#include "../EnemyTakanori.h"
#include "IEnemyState.h"

class EnemyHitState : public IEnemyState {
public:
  EnemyHitState() {};
  virtual ~EnemyHitState() {};

  void Init(EnemyTakanori *ins) override;
  void Update(EnemyTakanori *ins) override;

private:
  float timer_ = 0.0f;
  float timerMax_ = 1.0f;
};