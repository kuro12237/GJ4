#include "EnemyManager.h"

void EnemyManager::Init() {
  name_ = VAR_NAME(EnemyManager);
  this->CreateJson(name_, "Resources/Configs/Entitiys/EnemyTakanori/");

  this->SetValue<int>("EnemyMax", enemyMax_);
  enemyMax_ = this->GetValue<int>("EnemyMax");
  auto json = CLEYERA::Manager::GlobalVariables::GetInstance();
  //json->SaveFile(VAR_NAME(EnemyManager));

  this->enemySpawnPos_.resize(enemyMax_);

  for (size_t i = 0; i < static_cast<size_t>(enemyMax_); i++) {

    this->SetValue<Math::Vector::Vec3>("EnemyPos" + std::to_string(i),
                                       enemySpawnPos_[i]);
    enemySpawnPos_[i] =
        this->GetValue<Math::Vector::Vec3>("EnemyPos" + std::to_string(i));
  }

  json->SaveFile(VAR_NAME(EnemyManager));
}

void EnemyManager::Update() {

#ifdef _DEBUG

  JsonCompornent::JsonImGuiUpdate();
#endif // _DEBUG

  // player の z 座標
  float playerZ = this->playerPos_->z;

  for (auto it = this->enemySpawnPos_.begin(); it != enemySpawnPos_.end();) {
    float dz = std::abs(it->z - playerZ);
    if (dz < 40.0f) {
      SpawnEnemy(*it);
      saveEnemySpawnPos_.push_back(*it);
      it = enemySpawnPos_.erase(it); // spawn 済みの位置は消す
    } else {
      ++it;
    }
  }

}

void EnemyManager::SpawnEnemy(const Math::Vector::Vec3 &pos) {
  auto objManager = CLEYERA::Manager::ObjectManager::GetInstance();

  auto enemy = objManager->CreateObject<EnemyTakanori>(
      VAR_NAME(EnemyTakanori), std::make_shared<EnemyTakanori>());
  enemy.lock()->SetTranslate(pos);
  enemy.lock()->SetPlayerPos(playerPos_);
 
  enemy.lock()->SetWorldSetting(world_);
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
