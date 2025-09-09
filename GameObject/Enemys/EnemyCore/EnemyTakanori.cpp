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

  // コライダー作成
  ObjectComponent::CreateCollider(ColliderType::AABB);
  // 当たり判定関数セット
  collider_->SetHitCallFunc([this](std::weak_ptr<ObjectComponent> other) {
    this->OnCollision(other);
  });

  auto aabb = std::dynamic_pointer_cast<CLEYERA::Util::Collider::AABBCollider>(
      GetCollider().lock());
  aabb->GetAABB_().max = {1.0f, 1.0f, 1.0f};
  aabb->GetAABB_().min = {-1.0f, -1.0f, -1.0f};
}

void EnemyTakanori::Update() {}

void EnemyTakanori::OnCollision(
    [[maybe_unused]] std::weak_ptr<ObjectComponent> other) {
  
  SetMode(CLEYERA::Component::ObjectComponent::OBJ_MODE::REMOVE);
}
