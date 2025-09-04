#pragma once
#include "CLEYERA/CLEYERA.h"

#include "../Player/Player.h"
#include "../Player/PlayerCamera/PlayerCamera.h"

#include"../WorldSpeed/WorldSpeed.h"

class GameScene : public CLEYERA::Component::SceneComponent {
public:
  GameScene() {};
  ~GameScene() {};

  void Init() override;

  void Update(CLEYERA::Manager::SceneManager *ins) override;

  void Draw2d() override;

private:
  std::weak_ptr<Player> player_;
  std::shared_ptr<PlayerCamera> camera_ = nullptr;

  std::unique_ptr<WorldSetting> worldSpeed_ = nullptr;

};