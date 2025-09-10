#pragma once
#include "CLEYERA.h"

#include "../../../WorldSpeed/WorldSpeed.h"

class EnemyBullet : public CLEYERA::Component::ObjectComponent {
public:
  EnemyBullet() {};
  ~EnemyBullet() {};

  void Init() override;
  void Update() override;

  bool GetIsDead() { return isDead_; }
  void SetSpownPos(const Math::Vector::Vec3 &pos) { translate_ = pos; }
  void SetVelo(const Math::Vector::Vec3 &v) { velo_ = v; }
  void SetWorldSetting(std::weak_ptr<WorldSetting> w) { world_ = w; }

  /// <summary>
  /// 衝突時コールバック
  /// </summary>
  void OnCollision(std::weak_ptr<ObjectComponent> other);

private:
  void TimeFunc();
  bool isDead_ = false;

  Math::Vector::Vec3 velo_ = {0.0f, 0.0f, -0.1f};

  float time_ = 0.0f;
  float timeMax_ = 4.0f;

  std::weak_ptr<WorldSetting> world_;
};
