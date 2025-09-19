#include "IPlayerState.h"

void IPlayerState::ChangeModel(uint32_t handle) {}

void IPlayerState::Control() {

  auto translate = *this->translate_;

  float zToPos = translate.z - *zCenter_;

  Math::Vector::Vec2 joyPos =
      CLEYERA::Manager::InputManager::GetInstance()->JoyLPos();

  auto input = CLEYERA::Manager::InputManager::GetInstance();
  const float deadZone = 0.02f;

  if (std::abs(joyPos.x) > deadZone || std::abs(joyPos.y) > deadZone) {

    Math::Vector::Vec3 moveDir_ = {(joyPos.x * *speed_), 0.0f,
                                   (joyPos.y * *speed_)};
    *force_ = moveDir_;

    *force_ = moveDir_;
  }
  if (input->PushKey(DIK_W)) {
    force_->z += *speed_;

  } else if (input->PushKey(DIK_S)) {
    force_->z -= *speed_;
  }

  if (input->PushKey(DIK_A)) {
    force_->x -= *speed_;
  } else if (input->PushKey(DIK_D)) {

    force_->x += *speed_;
  }


  if (translate_->z > *zCenter_ + heightMinMax_) {
    if (force_->z > 0.0f) { // 壁の外へ押しているときだけ止める
      force_->z = 0.0f;
    }
  } else if (translate_->z < *zCenter_ - heightMinMax_) {

    if (force_->z < 0.0f) { // 壁の外へ押しているときだけ止める
      force_->z = 0.0f;
    }
  }

  if (translate_->x > widthMinMax_) {

    if (force_->x > 0.0f) {
      force_->x = 0.0f;
    }
  } else if (translate_->x < -widthMinMax_) {

    if (force_->x < 0.0f) {
      force_->x = 0.0f;
    }
  }


}