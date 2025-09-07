#include "EnemyTakanori.h"

using namespace CLEYERA::Component;

void EnemyTakanori::Init() {

  this->category_ = VAR_NAME(EnemyTakanori);
  this->CreateJsonSystem("Resources/Configs/Entitiys/EnemyTakanori/");

  uint32_t modelHandle = modelManager_->LoadModel(
      "Resources/Model/Enemy/Human_Nude", "Human_Nude");
  this->SetModelHandle(modelHandle);

  auto json = CLEYERA::Manager::GlobalVariables::GetInstance();
  json->SaveFile(name_);
  gameObject_->ColorData().color_ = {1.0f, 0.0f, 0.0f, 1.0f};
  translate_.y = 4.0f;
}

void EnemyTakanori::Update() {


}
