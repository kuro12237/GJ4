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

  if (ImGui::TreeNode(VAR_NAME(TemperatureGauge))) {

    this->TransformImGuiUpdate();
    ImGui::DragFloat2("size", &size_.x);
    ImGui::ColorEdit4("c", &sprite_->ColorData().color_.x);
    ImGui::DragFloat2("LT", &this->LeftTop_.x, 0.01f, 0.0f, 1.0f);
    ImGui::DragFloat2("LB", &this->LeftBottom_.x, 0.01f, 0.0f, 1.0f);
    ImGui::DragFloat2("RT", &this->RightTop_.x, 0.01f, 0.0f, 1.0f);
    ImGui::DragFloat2("RB", &this->RightBottom_.x, 0.01f, 0.0f, 1.0f);

    ImGui::SliderFloat("factor", &this->factor_, -1.0f, 1.0f);

    ImGui::TreePop();
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
