#include "GameScene.h"

void GameScene::Init() {

  loader_ = std::make_unique<SceneLoader>();
  loader_->LoadSceneData("GameScene");

  CLEYERA::Manager::GlobalVariables::GetInstance()->LoadFiles("Configs");

  enviromentObjs_ = loader_->SettingData();

  loader_.reset();


  auto objManager = CLEYERA::Manager::ObjectManager::GetInstance();

  player_ = objManager->CreateObject<Player>(VAR_NAME(Player),
                                             std::make_shared<Player>());

  camera_ = std::make_shared<PlayerCamera>();
  camera_->Init();

  worldSpeed_ = std::make_unique<WorldSetting>();
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

  camera_->Update();

  worldSpeed_->CalcSpeed(player_.lock()->GetTranslate());
  worldSpeed_->CalcSpeed(player_.lock()->GetZCenter());
  worldSpeed_->CalcSpeed(camera_->GetTranslate());

}

void GameScene::Draw2d() {}
