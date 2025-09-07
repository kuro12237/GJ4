#include "EnemyManager.h"

void EnemyManager::Init() {

SpownEnemy({0.0f, 0.0f, 40.0f});

}

void EnemyManager::Update() {}

void EnemyManager::SpownEnemy(const Math::Vector::Vec3 &pos) {
  auto objManager = CLEYERA::Manager::ObjectManager::GetInstance();

  auto enemy = objManager->CreateObject<EnemyTakanori>(
      VAR_NAME(EnemyTakanori), std::make_shared<EnemyTakanori>());
  enemy.lock()->SetTranslate(pos);

  enemies_.push_back(std::move(enemy));
}
