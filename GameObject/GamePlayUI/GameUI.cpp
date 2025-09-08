#include "GameUI.h"

void GameUI::Init() {

  temperatureBackUI_ = std::make_unique<TemperatureBackUI>();
  temperatureBackUI_->Init();
}

void GameUI::Update() { temperatureBackUI_->Update(); }

void GameUI::Draw2d() {

temperatureBackUI_->Draw(); }
