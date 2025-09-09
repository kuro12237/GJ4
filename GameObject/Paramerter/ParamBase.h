#pragma once
#include "CLEYERA.h"

class ParamBase {
public:
  ParamBase() {};
  virtual ~ParamBase() {};

  const float &GetTemperature() const { return this->temperature_; }

private:
protected:
  bool CalcTemperature(const Math::Vector::Vec3 &pos);

  float temperature_ = 0.0f;
  float temperatureSpeed_ = 0.005f;
};
