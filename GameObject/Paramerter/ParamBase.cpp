#include "ParamBase.h"

bool ParamBase::CalcTemperature(const Math::Vector::Vec3 &pos) {


  if (pos.x <= 0.0f) {
    temperature_ -= temperatureSpeed_;

  } else {
    temperature_ += temperatureSpeed_;
  }
  if (temperature_ >= 1.0f || temperature_ <= -1.0f) {
    isDead_ = true;
    return true;
  }
  return false;
}
