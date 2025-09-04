#include "PlayerCamera.h"

void PlayerCamera::Init() {

  this->name_ = VAR_NAME(PlayerCamera);
  this->CameraChange();

  translate_.y = 2.0f;

  
  CreateJsonSystem("Resources/Configs/Entitiys/PlayerCamera/");
  this->SetValue("rotate", rotate_);
  rotate_ = GetValue<Math::Vector::Vec3>("rotate");
  this->SetValue("translate", translate_);
  translate_ = GetValue<Math::Vector::Vec3>("translate");


}

void PlayerCamera::Update() {

#ifdef _DEBUG
  if (ImGui::TreeNode("PlayerCamera")) {
    this->ImGuiUpdate();
    jsonSystem_->JsonImGuiUpdate();
    ImGui::TreePop();
  }
#endif // _DEBUG

}
