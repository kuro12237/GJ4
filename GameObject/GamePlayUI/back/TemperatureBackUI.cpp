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

  if (ImGui::TreeNode("TestSprite")) {

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

  sprite_->ColorData().color_ = this->CalcColor(*this->temperatureParam_);

  sprite_->Update();
  WorldMatUpdate();
}


