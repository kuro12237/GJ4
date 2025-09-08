#include "TemperatureGaugeMarking.h"

void TemperatureGaugeMarkingUI::Init() {
  uint32_t texHandle = texManager_->LoadPngTex("Temperature/gaugeMarkings");
  this->Create();
  handle_ = texHandle;
  sprite_->SetTexHandle(handle_);
  this->size_ = texManager_->GetTexData(handle_).lock()->GetSize();

  this->scale_ = {0.5f, 0.5f, 0.5f};
  translate_ = {256.0f, 680.0f, 0.0f};
}

void TemperatureGaugeMarkingUI::Update() {


  sprite_->Update();
  WorldMatUpdate();

}
