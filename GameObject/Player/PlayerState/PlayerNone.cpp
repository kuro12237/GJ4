#include "PlayerNone.h"

void PlayerNone::Init(Player *ins) {

  auto modelManager = CLEYERA::Manager::ModelManager::GetInstance();

  uint32_t modelHandle =
      modelManager->LoadModel("Resources/Model/Player/normal", "normal");

  ins->SetModelHandle(modelHandle);
}

void PlayerNone::Update(Player *ins) { this->Control(); }
