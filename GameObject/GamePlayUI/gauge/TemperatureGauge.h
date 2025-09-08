#pragma once
#include "../GamePlayUIBase.h"

class TemperatureGauge : public GamePlayUIBase {
public:
  TemperatureGauge() {};
  ~TemperatureGauge() {};

  void Init() override;

  void Update() override;

private:
};
