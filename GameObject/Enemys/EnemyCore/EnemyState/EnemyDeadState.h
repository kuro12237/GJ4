#pragma once

#include "../EnemyTakanori.h"
#include "IEnemyState.h"

class EnemyDeadState : public IEnemyState {
public:
  EnemyDeadState() {};
  ~EnemyDeadState() {};

    void Init(EnemyTakanori *ins) override;
  void Update(EnemyTakanori *ins) override;

  bool GetIsDead() { return isDead_; }

private:
  bool isDead_ = false;
    
  float timer_ = 0.0f;
  float timerMax_ = 1.0f;
};

