#include "GameScene.h"

void GameScene::Init() {

  auto objManager = CLEYERA::Manager::ObjectManager::GetInstance();

  player_ = objManager->CreateObject<Player>(VAR_NAME(Player),
                                             std::make_shared<Player>());

  camera_ = std::make_shared<PlayerCamera>();
  camera_->Init();

    // 地形モデルの設定
  uint32_t modelHandle =
      CLEYERA::Manager::ModelManager::GetInstance()->LoadModel(
          "Resources/Model/Terrain", "terrain");
 

}

void GameScene::Update([[maybe_unused]] CLEYERA::Manager::SceneManager *ins) {

  camera_->Update();
}

void GameScene::Draw2d() {}
