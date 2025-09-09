#include "TemperatureBackUI.h"

void TemperatureBackUI::Init() {

  uint32_t texHandle = texManager_->LoadPngTex("Temperature/gaugeFlame");
  this->Create();
  handle_ = texHandle;
  sprite_->SetTexHandle(handle_);
  this->size_ = texManager_->GetTexData(handle_).lock()->GetSize();

  this->scale_ = {0.5f, 0.5f, 0.5f};
  translate_ = {256.0f, 680.0f, 0.0f};
}

void TemperatureBackUI::Update() {

 

  if (*temperatureParam_ <= 1.0f || *temperatureParam_ >= -1.0f) {

    sprite_->ColorData().color_ = this->CalcColor(*this->temperatureParam_);
  }

  sprite_->Update();
  WorldMatUpdate();
}
