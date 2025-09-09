#include "TitleScene.h"

TitleScene::~TitleScene(){
    LogoManager_.reset();
    subManager_.reset();
    SelectManager_.reset();
}

void TitleScene::Init() {

    // 最初にトランジションの初期化を行う
    BlackScreenTransition::GetInstance()->Init();

    LogoManager_ = std::make_unique<TitleLog>();
    LogoManager_->Init();

    // subManagerは常に表示・更新されるものと仮定
    subManager_ = std::make_unique<SubUI>();
    subManager_->Init();

    SelectManager_ = std::make_unique<SelectUI>();
    SelectManager_->Init();

    // シーン開始時にフェードインを開始
    currentState_ = State::FADING_IN;
    BlackScreenTransition::GetInstance()->StartFadeIn(1.0f, [this]() {
        // フェードインが終わったら、ロゴを表示する状態に移行
        this->currentState_ = State::LOGO_SHOW;
        });

}

void TitleScene::Update([[maybe_un_used]] CLEYERA::Manager::SceneManager* ins) {

    // 常に更新するものを先に呼ぶ
    LogoManager_->Update();
    subManager_->Update();

    // 毎フレーム、トランジション（フェード処理）の更新を呼び出す
    BlackScreenTransition::GetInstance()->Update();

    // フェード中はプレイヤーの入力を受け付けないようにする
    if (BlackScreenTransition::GetInstance()->IsActive()) {
        return; // ここで処理を中断
    }

    auto input = CLEYERA::Manager::InputManager::GetInstance();
    auto sceneManager = CLEYERA::Manager::SceneManager::GetInstance();


    // 現在の状態に応じて処理を切り替える
    switch (currentState_)
    {
    case State::FADING_IN:
        // コールバックが呼ばれるのを待つだけ（上のガード処理で入力は弾かれる）
        break;

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

        // Aボタンで選択を決定
        if (input->PushBotton(XINPUT_GAMEPAD_A)) {

            bool shouldTransition = false;

            SelectUI::SelectItem current = SelectManager_->GetCurrentSelect();

            if (current == SelectUI::SelectItem::GameState) {
                nextSceneName_ = "GameScene";
                shouldTransition = true;
            }
            else if (current == SelectUI::SelectItem::Tutorial) {
                nextSceneName_ = "TutorialScene"; // チュートリアルシーン名を指定
                shouldTransition = true;
            }
            else if (current == SelectUI::SelectItem::GameOver) {

                // ゲーム終了処理
                return;
            }

            // シーン遷移が必要な場合
            if (shouldTransition) {
                currentState_ = State::WAITING_FOR_FADE_OUT;
                // フェードアウトを開始
                BlackScreenTransition::GetInstance()->StartFadeOut(1.0f, [=]() {
                    sceneManager->ChangeScene(nextSceneName_);
                    return;
                    });
            }
        }
        
        break;
    case State::WAITING_FOR_FADE_OUT:

    break;
    }

}

void TitleScene::Draw2d() {
    // 常に描画するもの
    subManager_->Draw2D();
    LogoManager_->Draw2D();

    // 選択肢がアクティブな時だけ描画する
    if (currentState_ == State::SELECT_ACTIVE || currentState_ == State::WAITING_FOR_FADE_OUT) {
        SelectManager_->Draw2D();
    }

    BlackScreenTransition::GetInstance()->Draw2D();
}