#include "EnemyManager.h"

void EnemyManager::Init() {

  SpawnEnemy({-5.0f, 3.0f, 110.0f});
  SpawnEnemy({0.0f, 3.0f, 40.0f});
  SpawnEnemy({5.0f, 3.0f, 90.0f});
  SpawnEnemy({2.0f, 3.0f, 80.0f});
  SpawnEnemy({-4.0f, 3.0f, 70.0f});
}

void EnemyManager::Update() {

  for (auto &enemy : enemies_) {
    auto it = enemy.lock();

    if (!it)
      return;

    if (it->GetMode() ==
        CLEYERA::Component::ObjectComponent::OBJ_MODE::REMOVE) {
      SpawnEffect(it->GetTranslate());
    }
  }
}

void EnemyManager::SpawnEnemy(const Math::Vector::Vec3 &pos) {
  auto objManager = CLEYERA::Manager::ObjectManager::GetInstance();

  auto enemy = objManager->CreateObject<EnemyTakanori>(
      VAR_NAME(EnemyTakanori), std::make_shared<EnemyTakanori>());
  enemy.lock()->SetTranslate(pos);

  enemy.lock()->SetEffectSpawnFunc(
      [this](const Math::Vector::Vec3 &pos) { SpawnEffect(pos); });

  enemies_.push_back(std::move(enemy));
}

void EnemyManager::SpawnEffect(const Math::Vector::Vec3 &pos) {

  auto objManager = CLEYERA::Manager::ObjectManager::GetInstance();

  auto enemy = objManager->CreateObject<HitEnemyEffect>(
      VAR_NAME(HitEnemyEffect), std::make_shared<HitEnemyEffect>());
  enemy.lock()->SetSpownPos(pos);
  if (enemy.lock()) {

    effects_.push_back(std::move(enemy));
  }
}
