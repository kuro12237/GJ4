#include "ParamBase.h"

void ParamBase::CalcTemperature(const Math::Vector::Vec3 &pos) {
  if (pos.x <= 0.0f) {
    temperature_ -= temperatureSpeed_;

  } else {
    temperature_ += temperatureSpeed_;
  }
  if (temperature_ >= 1.0f || temperature_ <= -1.0f) {
    return;
  }
  ImGui::Begin("Param");

  ImGui::Text("temperature::%f", temperature_);

  ImGui::End();
}
