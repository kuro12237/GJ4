#include "TitleScene.h"

void TitleScene::Init() {
    LogoManager_ = std::make_unique<TitleLog>();
    LogoManager_->Init();

    // subManagerは常に表示・更新されるものと仮定
    subManager_ = std::make_unique<SubUI>();
    subManager_->Init();

    SelectManager_ = std::make_unique<SelectUI>();
    SelectManager_->Init();
}

void TitleScene::Update([[maybe_un_used]] CLEYERA::Manager::SceneManager* ins) {
    auto input = CLEYERA::Manager::InputManager::GetInstance();
    auto sceneManager = CLEYERA::Manager::SceneManager::GetInstance();


    // 常に更新するものを先に呼ぶ
    LogoManager_->Update();
    subManager_->Update();

    // 現在の状態に応じて処理を切り替える
    switch (currentState_)
    {
        // 状態：ロゴ表示中
    case State::LOGO_SHOW:
        // Aボタンが押されたら
        if (input->PushBotton(XINPUT_GAMEPAD_A)) {
            // ロゴのアニメーションを開始
            LogoManager_->StartOpeningAnimation(40.0f, 0.1f); // 40ピクセル、0.5秒かけて開く
            // 状態を「ロゴがアニメーション中」へ変更
            currentState_ = State::LOGO_ANIMATING;
        }
        break;

        // 状態：ロゴがアニメーション中
    case State::LOGO_ANIMATING:
        // ロゴのアニメーションが終わったら
        if (!LogoManager_->IsAnimating()) {
            // 状態を「選択肢が操作可能」へ変更
            currentState_ = State::SELECT_ACTIVE;
        }
        break;

        // 状態：選択肢が操作可能
    case State::SELECT_ACTIVE:
        // この状態の時だけ、SelectManagerを更新・操作する
        SelectManager_->Update();

        // 十字キー右
        if (input->PushBotton(XINPUT_GAMEPAD_DPAD_RIGHT)) {
            SelectManager_->OnDpadInput(1);
        }
        // 十字キー左
        if (input->PushBotton(XINPUT_GAMEPAD_DPAD_LEFT)) {
            SelectManager_->OnDpadInput(-1);
        }

        // Aボタン
        if (input->PushBotton(XINPUT_GAMEPAD_A)) {
            SelectUI::SelectItem current = SelectManager_->GetCurrentSelect();

            // 遷移先のシーン名を確定させる
            if (current == SelectUI::SelectItem::GameState) {
                nextSceneName_ = "GameScene";
            }
            else if (current == SelectUI::SelectItem::Tutorial) {
                nextSceneName_ = "TutorialScene"; // 例
            }
            else if (current == SelectUI::SelectItem::GameOver) {
                // ゲーム終了の場合はフェードさせずに直接終了させるなど、別の処理でも良い
                return; // この例では何もしない
            }

            // フェードアウトの準備
            if (!nextSceneName_.empty()) {
                fadeTimer_ = 0.0f;                // タイマーをリセット
                currentState_ = State::FADING_OUT; // フェードアウト状態に移行
            }
        }
        break;
        // ★★★ フェードアウト状態の処理を追加 ★★★
    case State::FADING_OUT:
    { // case内で変数を宣言するためスコープを追加
        const float DELTA_TIME_60FPS = 1.0f / 60.0f;
        fadeTimer_ += DELTA_TIME_60FPS;

        // Alpha値を計算 (1.0f -> 0.0f)
        float alpha = 1.0f - (fadeTimer_ / FADE_DURATION);
        if (alpha < 0.0f) { alpha = 0.0f; }

        // 全オブジェクトのAlpha値を設定
        LogoManager_->SetAllAlphas(alpha);
        SelectManager_->SetAllAlphas(alpha);
        subManager_->SetAllAlphas(alpha); // subManagerも忘れずに

        // フェードアウトが完了したらシーン遷移
        if (fadeTimer_ >= FADE_DURATION) {
            sceneManager->ChangeScene(nextSceneName_);
        }
    }
    break;
    }
}

void TitleScene::Draw2d() {
    // 常に描画するもの
    subManager_->Draw2D();
    LogoManager_->Draw2D();

    // 選択肢がアクティブな時だけ描画する
    if (currentState_ == State::SELECT_ACTIVE) {
        SelectManager_->Draw2D();
    }
}