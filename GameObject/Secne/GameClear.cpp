#include "GameClear.h"

void GameClear::Init(){
  CLEYERA::Manager::ObjectManager::GetInstance()->Clear();

	// 最初にトランジションの初期化を行う
	BlackScreenTransition::GetInstance()->Init();

	shouldTransition = false;

	camera_ = std::make_shared<CameraUI>();
	camera_->Init();

	GameClerUI_ = std::make_unique<GameClerUI>();
	GameClerUI_->Init();

	GameClerUI_->SetTranslate(Background_pos);
	GameClerUI_->SetScale(Background_Scale);

	TitleReturn_ = std::make_unique<TitleReturn>();
	TitleReturn_->Init();
	TitleReturn_->SetTranslate(Background_pos);
	TitleReturn_->SetScale(Background_Scale);

	BlackScreenTransition::GetInstance()->StartFadeIn(2.0f, [this]() {

		});
}

void GameClear::Update(CLEYERA::Manager::SceneManager* ins){
	auto input = CLEYERA::Manager::InputManager::GetInstance();
	auto sceneManager = CLEYERA::Manager::SceneManager::GetInstance();

	// シーン遷移が必要な場合
	if (shouldTransition) {
		// フェードアウトを開始
		BlackScreenTransition::GetInstance()->StartFadeOut(1.0f, [=]() {
			sceneManager->ChangeScene("TitleScene");
			return;
			});
	}
	// 毎フレーム、トランジション（フェード処理）の更新を呼び出す
	BlackScreenTransition::GetInstance()->Update();

	//各シーンで呼び出す
	if (BlackScreenTransition::GetInstance()->isOverReturn()) {
		return;
	}

	const float DELTA_TIME_60FPS = 1.0f / 60.0f;
	blinkTimer_ += DELTA_TIME_60FPS;
	// �w�肵�����Ԃ��o�߂�����
	if (blinkTimer_ >= BLINK_INTERVAL) {
		isTitleReturnVisible_ = !isTitleReturnVisible_; // �\���t���O�𔽓]������ (true -> false, false -> true)
		blinkTimer_ = 0.0f; // �^�C�}�[�����Z�b�g
	}

	GameClerUI_->SetTranslate(Background_pos);
	GameClerUI_->SetScale(Background_Scale);
	TitleReturn_->SetTranslate(TitleReturn_pos);
	TitleReturn_->SetScale(TitleReturn_scale);


	GameClerUI_->Update();
	TitleReturn_->Update();

	// フェード中はプレイヤーの入力を受け付けないようにする
	if (BlackScreenTransition::GetInstance()->IsActive()) {
		return; // ここで処理を中断
	}

	if (input->PushBotton(XINPUT_GAMEPAD_B)) {
		shouldTransition = true;
	}


}

void GameClear::Draw2d(){
	GameClerUI_->Draw();
	if (isTitleReturnVisible_) {
		TitleReturn_->Draw();
	}
	BlackScreenTransition::GetInstance()->Draw2D();
}
