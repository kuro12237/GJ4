#include "PlayerManager.h"

void PlayerManager::Init() {

  auto objManager = CLEYERA::Manager::ObjectManager::GetInstance();

  player_ = objManager->CreateObject<Player>(VAR_NAME(Player),
                                             std::make_shared<Player>());

  camera_ = std::make_shared<PlayerCamera>();
  camera_->Init();
}

void PlayerManager::Update() {

  auto input = CLEYERA::Manager::InputManager::GetInstance();
  auto objManager = CLEYERA::Manager::ObjectManager::GetInstance();

  bullets_.remove_if([](const std::weak_ptr<PlayerBullet> &b) {
    return b.lock()->GetIsDead();
  });

  camera_->Update();

  if (input->PushBottonPressed(XINPUT_GAMEPAD_A)) {

    auto bullet = objManager->CreateObject<PlayerBullet>(
        VAR_NAME(PlayerBullet), std::make_shared<PlayerBullet>());
    bullet.lock()->SetSpownPos(player_.lock()->GetTranslate());
    this->bullets_.push_back(std::move(bullet));
  }

  world_.lock()->CalcSpeed(player_.lock()->GetTranslate());
  world_.lock()->CalcSpeed(player_.lock()->GetZCenter());
  world_.lock()->CalcSpeed(camera_->GetTranslate());

  for (auto b : bullets_) {

    world_.lock()->CalcSpeed(b.lock()->GetTranslate());
  }
}
