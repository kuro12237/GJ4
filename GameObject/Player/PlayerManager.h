#pragma once
#include "../Player/Player.h"
#include "../Player/PlayerCamera/PlayerCamera.h"

#include "../WorldSpeed/WorldSpeed.h"
#include "PlayerBullet/PlayerBullet.h"

class PlayerManager {
public:
  PlayerManager() {};
  ~PlayerManager() {};

  void Init();

  void Update();

  void SetWorld(const std::weak_ptr<WorldSetting> &w) { world_ = w; }

private:
  std::weak_ptr<Player> player_;
  std::shared_ptr<PlayerCamera> camera_ = nullptr;

  std::weak_ptr<WorldSetting> world_;

  std::list<std::weak_ptr<PlayerBullet>> bullets_;
};
