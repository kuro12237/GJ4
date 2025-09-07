#pragma once
#include "../Paramerter/ParamBase.h"
#include "../Util/RailFunc/Rail.h"
#include "CLEYERA/CLEYERA.h"

class EnemyBase : public CLEYERA::Component::ObjectComponent, public ParamBase {
public:
  EnemyBase() {};
  virtual ~EnemyBase() {};

  virtual void Init() = 0;

  virtual void Update() = 0;

  void SetSpownPos(const Math::Vector::Vec3 &pos) { translate_ = pos; }

private:
protected:
  std::unique_ptr<Rail> rail_ = nullptr;
};
