#pragma once
#include "../../Util/Random/RandomGenerator.h"
#include "CLEYERA/CLEYERA.h"

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
  enum class EffectName { Sokai_Jp, Miwaku, NamaAsi, sokai };

  

  void EffectModelSelector(const int &num);

  float timer_ = 0.0f;
  float timerMax_ = 1.0f;

  std::unordered_map<EffectName, EnemyModelPath> filePathMap_;
};
