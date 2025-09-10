#pragma once
#include "CLEYERA.h"

class ParamBase {
public:
  ParamBase() {};
  virtual ~ParamBase() {};

  const float &GetTemperature() const { return this->temperature_; }

  bool GetIsDead() { return isDead_; }
  void SetStart(bool f) { isStart_ = f; }

private:
protected:
  bool CalcTemperature(const Math::Vector::Vec3 &pos);

  bool isStart_ = false;
  bool isDead_ = false;

  float temperature_ = 0.0f;
  float temperatureSpeed_ = 0.0025f;
};
