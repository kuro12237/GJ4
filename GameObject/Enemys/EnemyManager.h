#pragma once
#include "EnemyCore/EnemyTakanori.h"

#include"HitEffect/HitEffect.h"

class EnemyManager :public CLEYERA::Component::JsonCompornent{
public:
  EnemyManager() {};
  ~EnemyManager() {};

  void Init();

  void Update();

  void SpawnEnemy(const Math::Vector::Vec3 &pos);

  void SpawnEffect(const Math::Vector::Vec3 &pos);

  void SetPlayerPos(const Math::Vector::Vec3 *pos) { playerPos_ = pos; }

private:
	
	int enemyMax_ = 5;
  std::list<std::weak_ptr<EnemyBase>> enemies_;
  std::list<std::weak_ptr<HitEnemyEffect>> effects_;

  std::vector<Math::Vector::Vec3> enemySpawnPos_;
  std::vector<Math::Vector::Vec3> saveEnemySpawnPos_;

  std::string name_ = "";

  const Math::Vector::Vec3 *playerPos_ = nullptr;


  size_t killEnemyCount_ = 0;
};
