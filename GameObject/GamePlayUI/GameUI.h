#pragma once
#include "Temperature.h"
#include "back/TemperatureBackUI.h"

class GameUI {
public:
  GameUI() {};
  ~GameUI() {};

  void Init();

  void Update();

  void Draw2d();

private:

	//温度計
  std::unique_ptr<TemperatureBackUI> temperatureBackUI_ = nullptr;
};
