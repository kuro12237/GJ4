#include "CLEYERA/CLEYERA.h"
#include "GameObject/Secne/GameScene.h"
#include "GameObject/Secne/TitleSecne.h"

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

  sceneManager->ChangeScene("TitleScene");
  sceneManager->ChangeScene("GameScene");
 
 
  engine_->Run();
  engine_->Finalize();

  return 0;
}
