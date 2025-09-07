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
  bool isDead_ = false;
};
