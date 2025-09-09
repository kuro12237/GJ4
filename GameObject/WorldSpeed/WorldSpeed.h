#pragma once
#include"CLEYERA.h"

class WorldSetting {
public:
  WorldSetting() {};
  ~WorldSetting() {};

  void CalcSpeed(Math::Vector::Vec3 &pos) { pos.z += speed_; }
  void CalcSpeed(float &pos) { pos += speed_; }


private:

	float speed_ = 0.1f;

	float widthMinMax_ = 11.0f;
        float henghtMinMax_ = 6;

};
