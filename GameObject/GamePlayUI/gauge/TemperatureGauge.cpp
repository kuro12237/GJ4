#include "TemperatureGauge.h"

void TemperatureGauge::Init() {

  uint32_t texHandle = texManager_->LoadPngTex("Temperature/gaugeBar");
  this->Create();
  handle_ = texHandle;
  sprite_->SetTexHandle(handle_);
  this->size_ = texManager_->GetTexData(handle_).lock()->GetSize();

  this->scale_ = {0.5f, 0.5f, 0.5f};
  translate_ = {0.0f, 615.0f, 0.0f};
  anker_ = {};
}

void TemperatureGauge::Update() {
  this->size_ = texManager_->GetTexData(handle_).lock()->GetSize();



  if (*temperatureParam_ >= 1.0f || *temperatureParam_ <= -1.0f) {
    return;
  }

  float normal = (*this->temperatureParam_ + 1.0f) / 2.0f;

  float minUV = 0.13f;
  float maxUV = 1.0f;
  float uvX = (maxUV - minUV) * normal;

  Math::Vector::Vec2 uvLT = {minUV, 0.0f};
  Math::Vector::Vec2 uvLB = {minUV, 1.0f};
  Math::Vector::Vec2 uvRT = {uvX + minUV, 0.0f};
  Math::Vector::Vec2 uvRB = {uvX + minUV, 1.0f};

  RightTop_ = uvRT;
  RightBottom_ = uvRB;
  size_.x = size_.x * (uvX + minUV);

  sprite_->Update();
  WorldMatUpdate();
}
