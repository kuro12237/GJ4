#include "Rail.h"

void Rail::CalcRail() {

  if (railData_.size() < 2 || factorData_.empty()) {
    return; // 補間できない
  }

  auto itPoint = railData_.begin();
  auto itNext = std::next(itPoint);

  auto itFactor = factorData_.begin();

  for (; itNext != railData_.end() && itFactor != factorData_.end();
       ++itPoint, ++itNext, ++itFactor) {

    float t = *itFactor; // 0.0f ～ 1.0f
    Math::Vector::Vec3 point = Math::Vector::Func::Lerp<Math::Vector::Vec3>(*itPoint, *itNext, t);

    (*pos_) = point;

  }

  if (itNext == railData_.end() || itFactor == factorData_.end()) {
    isEnd_ = true;
  }
}
