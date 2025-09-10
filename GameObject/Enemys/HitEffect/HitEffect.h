#pragma once
#include "../../Util/Random/RandomGenerator.h"
#include "CLEYERA.h"

struct EnemyModelPath {
  std::string directory_;
  std::string name_;
};

class HitEnemyEffect : public CLEYERA::Component::ObjectComponent {
public:
  HitEnemyEffect() {};
  ~HitEnemyEffect() {};

  void Init() override;

  void Update() override;

  void SetSpownPos(const Math::Vector::Vec3 &pos) { translate_ = pos; }

private:
  Math::Vector::Vec4 RandomColorHSV();

  enum class EffectName { Sokai_Jp, Miwaku, NamaAsi, sokai };

  float EaseInBack(float x) {
    return (x == 0.0f) ? 0.0f : std::pow(2.0f, 10.0f * x - 10.0f);
  }

  float LerpEase(float start, float end, float t) {
    float easedT = EaseInBack(t);
    return start + (end - start) * easedT;
  }

  void EffectModelSelector(const int &num);

  float timer_ = 0.0f;
  float timerMax_ = 1.0f;

  std::unordered_map<EffectName, EnemyModelPath> filePathMap_;
};
