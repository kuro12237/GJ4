#pragma once
#include "CLEYERA/CLEYERA.h"

class PlayerBullet : public CLEYERA::Component::ObjectComponent {
public:
  PlayerBullet() {};
  ~PlayerBullet() {};

  void Init() override;
  void Update() override;

  bool GetIsDead() { return isDead_; }
  void SetSpownPos(const Math::Vector::Vec3 &pos) { translate_ = pos; }

private:
  void TimeFunc();

  bool isDead_ = false;


  float time_ = 0.0f;
  float timeMax_ = 2.0f;
};
