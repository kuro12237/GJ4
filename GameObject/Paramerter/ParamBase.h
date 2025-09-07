#pragma once
#include "CLEYERA/CLEYERA.h"

class ParamBase {
public:
  ParamBase() {};
  virtual ~ParamBase() {};

private:
protected:
  void CalcTemperature(const Math::Vector::Vec3 &pos);

  float temperature_ = 0.0f;
};
