#include "GameOver.h"

void GameOver::Init() {
  CLEYERA::Manager::ObjectManager::GetInstance()->Clear();

	// 最初にトランジションの初期化を行う
	BlackScreenTransition::GetInstance()->Init();

	camera_ = std::make_shared<CameraUI>();
	camera_->Init();

	shouldTransition = false;

	GameOverUI_ = std::make_unique<GameOverUI>();
	GameOverUI_->Init();
	GameOverUI_->SetTranslate(Background_pos);
	GameOverUI_->SetScale(Background_Scale);

	TitleReturn_ = std::make_unique<TitleReturn>();
	TitleReturn_->Init();
	TitleReturn_->SetTranslate(Background_pos);
	TitleReturn_->SetScale(Background_Scale);

	BlackScreenTransition::GetInstance()->StartFadeIn(2.0f, [this]() {

		});
}

void GameOver::Update(CLEYERA::Manager::SceneManager* ins) {

	auto input = CLEYERA::Manager::InputManager::GetInstance();
	auto sceneManager = CLEYERA::Manager::SceneManager::GetInstance();


	// シーン遷移が忁E��な場吁E
	if (shouldTransition) {
		// フェードアウトを開姁E
		BlackScreenTransition::GetInstance()->StartFadeOut(1.0f, [=]() {
			sceneManager->ChangeScene("TitleScene");
			return;
			});
	}
	// 毎フレーム、トランジション�E�フェード�E琁E���E更新を呼び出ぁE
	BlackScreenTransition::GetInstance()->Update();

	//吁E��ーンで呼び出ぁE
	if (BlackScreenTransition::GetInstance()->isOverReturn()){
		return;
	}

	const float DELTA_TIME_60FPS = 1.0f / 60.0f;
	blinkTimer_ += DELTA_TIME_60FPS;

	// �w�肵�����Ԃ��o�߂�����
	if (blinkTimer_ >= BLINK_INTERVAL) {
		isTitleReturnVisible_ = !isTitleReturnVisible_; // �\���t���O�𔽓]������ (true -> false, false -> true)
		blinkTimer_ = 0.0f; // �^�C�}�[�����Z�b�g
	}

	GameOverUI_->SetTranslate(Background_pos);
	GameOverUI_->SetScale(Background_Scale);
	TitleReturn_->SetTranslate(TitleReturn_pos);
	TitleReturn_->SetScale(TitleReturn_scale);


	GameOverUI_->Update();
	TitleReturn_->Update();

	// フェード中はプレイヤーの入力を受け付けなぁE��ぁE��する
	if (BlackScreenTransition::GetInstance()->IsActive()) {
		return;
	}

	if (input->PushBotton(XINPUT_GAMEPAD_B)|| input->PushKey(DIKEYBOARD_SPACE)) {
		shouldTransition = true;
	}

}

void GameOver::Draw2d() {

	GameOverUI_->Draw();
	if (isTitleReturnVisible_) {
		TitleReturn_->Draw();
	}
	BlackScreenTransition::GetInstance()->Draw2D();

}
