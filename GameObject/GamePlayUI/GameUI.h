#pragma once
#include "Temperature.h"
#include "back/TemperatureBackUI.h"
#include "gauge/TemperatureGauge.h"
#include"gaugeMarking/TemperatureGaugeMarking.h"
#include "Operation/Operation.h"

class GameUI {
public:
  GameUI() {};
  ~GameUI() {};

  void Init();

  void Update();

  void Draw2d();

  void SetTemperatureParam(const float &num) { temperatureParam_ = &num; }

private:
  const float *temperatureParam_ = nullptr;

  // 温度計
  std::unique_ptr<TemperatureBackUI> temperatureBackUI_ = nullptr;
  std::unique_ptr<TemperatureGauge> temperatureGaugeUI_ = nullptr;
  std::unique_ptr<TemperatureGaugeMarkingUI> temperatureGaugeMarkingUI_ = nullptr;
  std::unique_ptr<Operation> OperationUI_ = nullptr;

};
