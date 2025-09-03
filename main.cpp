#include "CLEYERA/CLEYERA.h"
#include "GameObject/Secne/TitleSecne.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

  std::unique_ptr<Engine> engine_ = std::make_unique<Engine>();

  engine_->Init();
  // �n�`���f���̐ݒ�
      uint32_t modelHandle =
      CLEYERA::Manager::ModelManager::GetInstance()->LoadModel("Resources/Model/Terrain/", "terrain");
  CLEYERA::Manager::Terrain::GetInstance()->ChengeData(modelHandle);
  
  auto sceneManager = CLEYERA::Manager::SceneManager::GetInstance();

  sceneManager->RegisterScene<TitleScene>("TitleScene");
  sceneManager->ChangeScene("TitleScene");

  engine_->Run();
  engine_->Finalize();

  return 0;
}

