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

  void SetPlayerPos(const Math::Vector::Vec3 *PlayerPos) { playerPos_ = PlayerPos; }
  void SetZInterval(const float *interval) { zInterval_ = interval; };


private:
protected:
  
  std::string prevStateName_ = "";

  Math::Vector::Vec3 *translate_ = nullptr;
  const Math::Vector::Vec3 *playerPos_ = nullptr;
  const float *zInterval_ = nullptr;
};
