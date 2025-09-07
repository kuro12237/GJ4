#include "GameScene.h"

void GameScene::Init() {

  loader_ = std::make_unique<SceneLoader>();
  loader_->LoadSceneData("GameScene");

  CLEYERA::Manager::GlobalVariables::GetInstance()->LoadFiles("Configs");

  enviromentObjs_ = loader_->SettingData();

  loader_.reset();

  auto objManager = CLEYERA::Manager::ObjectManager::GetInstance();


  worldSpeed_ = std::make_shared<WorldSetting>();

  playerManager_ = std::make_unique<PlayerManager>();
  playerManager_->Init();
  playerManager_->SetWorld(worldSpeed_);

  enemyManager_ = std::make_unique<EnemyManager>();
  enemyManager_->Init();

  // 地形モデルの設定
  uint32_t modelHandle =
      CLEYERA::Manager::ModelManager::GetInstance()->LoadModel(
          "Resources/Model/Terrain/", "terrain");
  CLEYERA::Manager::Terrain::GetInstance()->ChengeData(modelHandle);
}

void GameScene::Update([[maybe_unused]] CLEYERA::Manager::SceneManager *ins) {

  if (ImGui::Button("SceneReLoad")) {
    ins->ChangeScene("GameScene");
    return;
  }

  playerManager_->Update();
  enemyManager_->Update();
}

void GameScene::Draw2d() {}
