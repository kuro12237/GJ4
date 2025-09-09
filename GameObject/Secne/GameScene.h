#pragma once
#include "CLEYERA.h"

#include "../WorldSpeed/WorldSpeed.h"

#include "../Player/PlayerManager.h"
#include"../Enemys/EnemyManager.h"
#include "../Util/SceneLoader.h"

#include"../GamePlayUI/GameUI.h"

#include "BlackScreenTransition.h"


class GameScene : public CLEYERA::Component::SceneComponent {
public:
  GameScene() {};
  ~GameScene() {};

  void Init() override;

  void Update(CLEYERA::Manager::SceneManager *ins) override;

  void Draw2d() override;

  void Finalize() override;

private:
 
  std::shared_ptr<WorldSetting> worldSpeed_ = nullptr;

  std::unique_ptr<SceneLoader> loader_ = nullptr;

  std::vector<std::weak_ptr<EnvironmentObject>> enviromentObjs_;

  std::unique_ptr<PlayerManager> playerManager_ = nullptr;

  std::unique_ptr<EnemyManager> enemyManager_ = nullptr;

  std::unique_ptr<GameUI> ui_ = nullptr;
};