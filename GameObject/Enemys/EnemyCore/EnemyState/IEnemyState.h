#pragma once
#include "CLEYERA.h"

class EnemyTakanori;
class IEnemyState {
public:
  IEnemyState() {};
  virtual ~IEnemyState() {};

  virtual void Init(EnemyTakanori *ins) = 0;

  virtual void Update(EnemyTakanori *ins) = 0;

  void SetPos(Math::Vector::Vec3 *pos) { translate_ = pos; }

private:
protected:
  
  std::string prevStateName_ = "";

  Math::Vector::Vec3 *translate_ = nullptr;
};
