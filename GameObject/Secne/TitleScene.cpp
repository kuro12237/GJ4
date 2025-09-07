#include "TitleScene.h"

void TitleScene::Init() {
  LogoManager_ = std::make_unique<TitleLog>();
  LogoManager_->Init();

  subManager_ = std::make_unique<SubUI>();
  subManager_->Init();

  SelectManager_ = std::make_unique<SelectUI>();
  SelectManager_->Init();   
}

void TitleScene::Update([[maybe_un_used]] CLEYERA::Manager::SceneManager *ins) {

  auto input = CLEYERA::Manager::InputManager::GetInstance();
  // 十字キー右
  if (input->PushBotton(XINPUT_GAMEPAD_DPAD_RIGHT)) {
      SelectManager_->OnDpadInput(1); // 右方向
  }
  // 十字キー左
  if (input->PushBotton(XINPUT_GAMEPAD_DPAD_LEFT)) {
      SelectManager_->OnDpadInput(-1); // 左方向

  }

  // Aボタン
  if (input->PushBotton(XINPUT_GAMEPAD_A)) {
      // 現在選択されている項目に応じてシーン遷移などを変える
      SelectUI::SelectItem current = SelectManager_->GetCurrentSelect();

      if (current == SelectUI::SelectItem::GameState) {
          auto sceneManager = CLEYERA::Manager::SceneManager::GetInstance();
          sceneManager->ChangeScene("GameScene");
          return;
      }
      else if (current == SelectUI::SelectItem::Tutorial) {
          // チュートリアルシーンへ
      }
      else if (current == SelectUI::SelectItem::GameOver) {
          // ゲーム終了処理
      }
  }

  LogoManager_->Update();
  subManager_->Update();
  SelectManager_->Update();
}

void TitleScene::Draw2d() {

  subManager_->Draw2D();
  LogoManager_->Draw2D();
  SelectManager_->Draw2D();
}
