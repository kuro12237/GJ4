#include "EnemyManager.h"

void EnemyManager::Init() {

SpownEnemy({-5.0f, 0.0f, 110.0f});
  SpownEnemy({0.0f, 0.0f, 40.0f});
SpownEnemy({5.0f, 0.0f, 90.0f});
  SpownEnemy({2.0f, 0.0f, 80.0f});
SpownEnemy({-4.0f, 0.0f, 70.0f});
}

void EnemyManager::Update() {

}

void EnemyManager::SpownEnemy(const Math::Vector::Vec3 &pos) {
  auto objManager = CLEYERA::Manager::ObjectManager::GetInstance();

  auto enemy = objManager->CreateObject<EnemyTakanori>(
      VAR_NAME(EnemyTakanori), std::make_shared<EnemyTakanori>());
  enemy.lock()->SetTranslate(pos);

  enemies_.push_back(std::move(enemy));
}
