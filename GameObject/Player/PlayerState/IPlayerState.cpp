#include "IPlayerState.h"

void IPlayerState::ChangeModel(uint32_t handle) {}

void IPlayerState::Control() {

  auto translate = *this->translate_;

  float zToPos = translate.z - zCenter_;

  Math::Vector::Vec2 joyPos =
      CLEYERA::Manager::InputManager::GetInstance()->JoyLPos();
  const float deadZone = 0.02f;

  if (std::abs(joyPos.x) > deadZone || std::abs(joyPos.y) > deadZone) {

    Math::Vector::Vec3 moveDir_ = {(joyPos.x * speed_), 0.0f,
                                   (joyPos.y * speed_)};
    *force_ = moveDir_;

    *force_ = moveDir_;
  }
  // --- Z方向の範囲制御 ---
  if (zToPos > heightMinMax_) {
    translate.z = zCenter_ + heightMinMax_;
    force_->z = 0.0f;
  } else if (zToPos < -heightMinMax_) {
    translate.z = zCenter_ - heightMinMax_;
    force_->z = 0.0f;
  }

  // --- X方向の範囲制御 ---
  if (translate.x > widthMinMax_) {
    translate.x = widthMinMax_;
    force_->x = 0.0f;
  } else if (translate.x < -widthMinMax_) {
    translate.x = -widthMinMax_;
    force_->x = 0.0f;
  }
}