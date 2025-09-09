#pragma once
#include "CLEYERA.h"

class Rail {
public:
  Rail() {};
  ~Rail() {};

  void CalcRail();

  void SetPos(Math::Vector::Vec3 *pos) { pos_ = pos; }
  bool GetIsEnd() { return isEnd_; }

private:
  bool isEnd_ = false;

  float startTime_ = 0.0f;
  std::list<Math::Vector::Vec3> railData_;
  std::list<float> factorData_;

  Math::Vector::Vec3 *pos_ = nullptr;
};
