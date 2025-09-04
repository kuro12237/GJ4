#include "PlayerCamera.h"

void PlayerCamera::Init() {

  this->name_ = VAR_NAME(TestCamera);
  // この関数を呼び出すとこのカメラからの描画に変わる
  this->CameraChange();
}

void PlayerCamera::Update() {

  if (ImGui::TreeNode("PlayerCamera")) {
    ImGui::DragFloat3("rotate", &rotate_.x);
    ImGui::DragFloat3("translate", &translate_.x);

    ImGui::TreePop();
  }
}
