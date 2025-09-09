#pragma once
#include "CLEYERA.h"

class GamePlayUIBase : public SpriteComponent {
public:
  GamePlayUIBase() {};
  ~GamePlayUIBase() {};

  virtual void Init() = 0;

  virtual void Update() = 0;

  void SetTemperatureParam(const float &num) { temperatureParam_ = &num; }

protected:
  Math::Vector::Vec4 CalcColor(float x);

  float factor_ = 0.0f;
  const float *temperatureParam_ = nullptr;

private:
};
