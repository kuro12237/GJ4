#pragma once
#include "../GamePlayUIBase.h"
#include "CLEYERA/CLEYERA.h"

class TemperatureGaugeMarkingUI : public GamePlayUIBase {
public:
  TemperatureGaugeMarkingUI() {};
  ~TemperatureGaugeMarkingUI() {};

  void Init() override;

  void Update() override;

private:
};


