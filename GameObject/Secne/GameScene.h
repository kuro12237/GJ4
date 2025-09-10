#pragma once
#include "CLEYERA.h"

#include "../WorldSpeed/WorldSpeed.h"

#include "../Player/PlayerManager.h"
#include"../Enemys/EnemyManager.h"
#include "../Util/SceneLoader.h"

#include"../GamePlayUI/GameUI.h"

#include "../GamePlayStandbyUI/GamePlayStandbyUI.h"

#include "BlackScreenTransition.h"
#include "Camera.h"


class GameScene : public CLEYERA::Component::SceneComponent {
public:
  GameScene() {};
  ~GameScene() {};

  void Init() override;

  void Update(CLEYERA::Manager::SceneManager *ins) override;

  void Draw2d() override;

  void Finalize() override;

private:

    enum class State {
        Standby, // カウントダウン中
        Playing,  // ゲームプレイ中
        WAITING_FOR_FADE_OUT,//フェードアウト中
    };


    State currentState_ = State::Standby;
    std::string nextSceneName_ = "";    // 遷移先のシーン名を保持する変数
    std::unique_ptr<GamePlayStandbyUI> standbyUI_;
    

 
  std::shared_ptr<WorldSetting> worldSpeed_ = nullptr;

  std::unique_ptr<SceneLoader> loader_ = nullptr;

  std::vector<std::weak_ptr<EnvironmentObject>> enviromentObjs_;

  std::unique_ptr<PlayerManager> playerManager_ = nullptr;

  std::unique_ptr<EnemyManager> enemyManager_ = nullptr;

  std::unique_ptr<GameUI> ui_ = nullptr;


};