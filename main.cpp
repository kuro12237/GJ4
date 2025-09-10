#include "CLEYERA.h"
#include "GameObject/Secne/BlackScreenTransition.h"
#include "GameObject/Secne/GameScene.h"
#include "GameObject/Secne/TitleScene.h"
#include "GameObject/Secne/TutorialScene.h"
#include "GameObject//Secne/GameClear.h"
#include "GameObject/Secne/GameOver.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

  std::unique_ptr<Engine> engine_ = std::make_unique<Engine>();

  engine_->Init();
  // 地形モデルの設定
  uint32_t modelHandle =
      CLEYERA::Manager::ModelManager::GetInstance()->LoadModel(
          "Resources/Model/Terrain/", "terrain");
  CLEYERA::Manager::Terrain::GetInstance()->ChengeData(modelHandle);

  auto sceneManager = CLEYERA::Manager::SceneManager::GetInstance();

  sceneManager->RegisterScene<TitleScene>("TitleScene");
  sceneManager->RegisterScene<GameScene>("GameScene");
  sceneManager->RegisterScene<TutorialScene>("TutorialScene");
  sceneManager->RegisterScene<GameClear>("GameClear");
  sceneManager->RegisterScene<GameOver>("GameOver");


  //sceneManager->ChangeScene("GameClear");
  sceneManager->ChangeScene("TitleScene");

  while (CLEYERA::Base::Win::WinApp::GetInstance()->WinMsg()) {
    engine_->Run();
  };
  BlackScreenTransition::GetInstance()->Finalize();

  engine_->Finalize();

  return 0;
}
