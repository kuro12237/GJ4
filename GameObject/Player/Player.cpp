#include "Player.h"

void Player::Init() {

  this->category_ = VAR_NAME(Player);
  uint32_t modelHandle = modelManager_->LoadModel(
      "Resources/Model/Player/Human_Nude", "Human_Nude");
  this->SetModelHandle(modelHandle);

  CreateJsonSystem("Resources/Configs/Entitiys/Player/");

  this->SetValue<Math::Vector::Vec3>("translate", translate_);
  translate_ = this->GetValue<Math::Vector::Vec3>("translate");

  this->SetValue<float>("speed", speed_);
  speed_ = this->GetValue<float>("speed");

  this->isGravity_ = false;
  this->isTerrainHit_ = false;

  mass_ = 0.5f;
  zCenter_ = translate_.z;
}

void Player::Update() {

#ifdef _DEBUG

  this->ImGuiUpdate();

#endif // _DEBUG
  Control();

  TransformUpdate();
}

void Player::Control() {

   
  float zToPos = translate_.z - zCenter_;



  Math::Vector::Vec2 joyPos =
      CLEYERA::Manager::InputManager::GetInstance()->JoyLPos();
  const float deadZone = 0.02f;

  if (std::abs(joyPos.x) > deadZone || std::abs(joyPos.y) > deadZone) {

    Math::Vector::Vec3 moveDir_ = {(joyPos.x * speed_), 0.0f,
                                   (joyPos.y * speed_)};
    force_ = moveDir_;

 
    force_ = moveDir_;

  
  }
  // --- Z方向の範囲制御 ---
  if (zToPos > heightMinMax_) {
    translate_.z = zCenter_ + heightMinMax_;
    force_.z = 0.0f;
  } else if (zToPos < -heightMinMax_) {
    translate_.z = zCenter_ - heightMinMax_;
    force_.z = 0.0f;
  }

   // --- X方向の範囲制御 ---
  if (translate_.x > widthMinMax_) {
    translate_.x = widthMinMax_;
    force_.x = 0.0f;
  } else if (translate_.x < -widthMinMax_) {
    translate_.x = -widthMinMax_;
    force_.x = 0.0f;
  }

}
