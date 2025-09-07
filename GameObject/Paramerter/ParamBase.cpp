#include "ParamBase.h"

void ParamBase::CalcTemperature(const Math::Vector::Vec3 &pos) {

  ImGui::Begin("Param");

  ImGui::Text("temperature::%f", temperature_);
  if (pos.x <= 0.0f) {
    temperature_ += 0.1f;

  } else {
    temperature_ -= 0.1f;
  }

  ImGui::End();
}
