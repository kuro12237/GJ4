#include "GamePlayUIBase.h"

Math::Vector::Vec4 GamePlayUIBase::CalcColor(float x) {
  // 範囲制限
  x = std::clamp(x, -1.0f, 1.0f);

  Math::Vector::Vec4 blue = {27.0f / 255.0f, 50.0f / 255.0f, 183.0f / 255.0f,
                             1.0f};
  Math::Vector::Vec4 white = {1.0f, 1.0f, 1.0f, 1.0f};
  Math::Vector::Vec4 red = {236.0f / 255.0f, 22.0f / 255.0f, 22.0f / 255.0f,
                            1.0f};

  if (x <= 0.0f) {
    // [-1,0] → [0,1] に正規化
    float t = (x + 1.0f) / 1.0f;
    Math::Vector::Vec4 result = {
        Math::Vector::Func::Lerp<float>(blue.x, white.x, t),
        Math::Vector::Func::Lerp<float>(blue.y, white.y, t),
        Math::Vector::Func::Lerp<float>(blue.z, white.z, t),
        Math::Vector::Func::Lerp<float>(blue.w, white.w, t)};

    return result;
  } else {
    // [0,1] → [0,1] に正規化
    float t = x / 1.0f;
    Math::Vector::Vec4 result = {
        Math::Vector::Func::Lerp<float>(white.x, red.x, t),
        Math::Vector::Func::Lerp<float>(white.y, red.y, t),
        Math::Vector::Func::Lerp<float>(white.z, red.z, t),
        Math::Vector::Func::Lerp<float>(white.w, red.w, t)};

    return result;
  }
}