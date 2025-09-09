#include "GameScene.h"

void GameScene::Init() {

  CLEYERA::Manager::ObjectManager::GetInstance()->Clear();
  // ファイル
  loader_ = std::make_unique<SceneLoader>();
  loader_->LoadSceneData("GameScene");
  CLEYERA::Manager::GlobalVariables::GetInstance()->LoadFiles("Configs");
  enviromentObjs_ = loader_->SettingData();
  loader_.reset();

  // class
  worldSpeed_ = std::make_shared<WorldSetting>();

  playerManager_ = std::make_unique<PlayerManager>();
  playerManager_->Init();
  playerManager_->SetWorld(worldSpeed_);

  enemyManager_ = std::make_unique<EnemyManager>();
  enemyManager_->Init();


  ui_ = std::make_unique<GameUI>();
  ui_->SetTemperatureParam(
      playerManager_->GetPlayer().lock()->GetTemperature());

  ui_->Init();

  // setting

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
  CLEYERA::Manager::ObjectManager::GetInstance();
  playerManager_->Update();
  enemyManager_->Update();

  ui_->Update();
}

void GameScene::Draw2d() { ui_->Draw2d(); }

void GameScene::Finalize() {  }
