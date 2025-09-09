#pragma once
#include "EnemyNoneState.h"
#include"../EnemyTakanori.h"

class EnemyMoveState : public IEnemyState {
public:
  EnemyMoveState() {};
  virtual ~EnemyMoveState() {};

  virtual void Init(EnemyTakanori *ins);

  virtual void Update(EnemyTakanori *ins);

private:

  float widthMinMax_ = 9.0f;

  float speed_ = 0.1f;

  float attackTimer_ = 0.0f;
  float attackTimerMax_ = 1.5f;

};
