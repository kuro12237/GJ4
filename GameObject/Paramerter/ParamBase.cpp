#include "ParamBase.h"

void ParamBase::CalcTemperature(const Math::Vector::Vec3 &pos) {

  ImGui::Begin("Param");

  ImGui::Text("temperature::%f", temperature_);
  if (pos.x <= 0.0f) {
    temperature_ += temperatureSpeed_;

  } else {
    temperature_ -= temperatureSpeed_;
  }

  ImGui::End();
}
