#pragma once
#include "../Paramerter/ParamBase.h"
#include "../Util/RailFunc/Rail.h"
#include "CLEYERA.h"

#include "../WorldSpeed/WorldSpeed.h"


class EnemyBase : public CLEYERA::Component::ObjectComponent, public ParamBase {
public:
  EnemyBase() {};
  virtual ~EnemyBase() {};

  virtual void Init() = 0;

  virtual void Update() = 0;

  void SetSpownPos(const Math::Vector::Vec3 &pos) { translate_ = pos; }

  /// <summary>
  /// 衝突時コールバック
  /// </summary>
  virtual void OnCollision(std::weak_ptr<ObjectComponent> other) = 0;

  void SetEffectSpawnFunc(
      const std::function<void(const Math::Vector::Vec3 &)> &func) {
    effectSpawn_ = func;
  }

  void Finalize() override {
  
  };
  void SetWorldSetting(std::weak_ptr<WorldSetting> w) { world_ = w; }
  void SetPlayerPos(const Math::Vector::Vec3 *pos) { this->playerPos_ = pos; }

  bool GetIsDead() { return isDead_; }

private:
protected:
  std::function<void(const Math::Vector::Vec3 &)> effectSpawn_;

  std::unique_ptr<Rail> rail_ = nullptr;

  std::weak_ptr<WorldSetting> world_;

  const Math::Vector::Vec3 *playerPos_ = nullptr;

  bool isDead_ = false;
};
