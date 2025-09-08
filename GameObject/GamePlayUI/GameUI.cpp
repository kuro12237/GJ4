#include "GameUI.h"

void GameUI::Init() {

  temperatureBackUI_ = std::make_unique<TemperatureBackUI>();
  temperatureBackUI_->SetTemperatureParam(*temperatureParam_);
  temperatureBackUI_->Init();

  temperatureGaugeUI_ = std::make_unique<TemperatureGauge>();
  temperatureGaugeUI_->SetTemperatureParam(*temperatureParam_);
  temperatureGaugeUI_->Init();

  temperatureGaugeMarkingUI_ = std::make_unique<TemperatureGaugeMarkingUI>();
  temperatureGaugeMarkingUI_->SetTemperatureParam(*temperatureParam_);
  temperatureGaugeMarkingUI_->Init();


}

void GameUI::Update() {
  temperatureBackUI_->Update();

  temperatureGaugeUI_->Update();
  temperatureGaugeMarkingUI_->Update();
}

void GameUI::Draw2d() {

  temperatureBackUI_->Draw();
  temperatureGaugeUI_->Draw();
  temperatureGaugeMarkingUI_->Draw();
}
