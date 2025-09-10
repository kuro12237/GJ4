#pragma once
#include "IEnemyState.h"
#include"EnemyMoveState.h"

class EnemyNoneState : public IEnemyState {
public:
  EnemyNoneState() {};
  virtual ~EnemyNoneState() {};

  void Init(EnemyTakanori *ins) override;
  void Update(EnemyTakanori *ins) override;

private:
 


};
