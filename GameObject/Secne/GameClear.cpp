#include "GameClear.h"

void GameClear::Init(){
  CLEYERA::Manager::ObjectManager::GetInstance()->Clear();

	// 譛蛻昴↓繝医Λ繝ｳ繧ｸ繧ｷ繝ｧ繝ｳ縺ｮ蛻晄悄蛹悶ｒ陦後≧
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

	// 繧ｷ繝ｼ繝ｳ驕ｷ遘ｻ縺悟ｿ・ｦ√↑蝣ｴ蜷・
	if (shouldTransition) {
		// 繝輔ぉ繝ｼ繝峨い繧ｦ繝医ｒ髢句ｧ・
		BlackScreenTransition::GetInstance()->StartFadeOut(1.0f, [=]() {
			sceneManager->ChangeScene("TitleScene");
			return;
			});
	}
	// 豈弱ヵ繝ｬ繝ｼ繝縲√ヨ繝ｩ繝ｳ繧ｸ繧ｷ繝ｧ繝ｳ・医ヵ繧ｧ繝ｼ繝牙・逅・ｼ峨・譖ｴ譁ｰ繧貞他縺ｳ蜃ｺ縺・
	BlackScreenTransition::GetInstance()->Update();

	//蜷・す繝ｼ繝ｳ縺ｧ蜻ｼ縺ｳ蜃ｺ縺・
	if (BlackScreenTransition::GetInstance()->isOverReturn()) {
		return;
	}

	const float DELTA_TIME_60FPS = 1.0f / 60.0f;
	blinkTimer_ += DELTA_TIME_60FPS;
	// 指定した時間が経過したら
	if (blinkTimer_ >= BLINK_INTERVAL) {
		isTitleReturnVisible_ = !isTitleReturnVisible_; // 表示フラグを反転させる (true -> false, false -> true)
		blinkTimer_ = 0.0f; // タイマーをリセット
	}

	GameClerUI_->SetTranslate(Background_pos);
	GameClerUI_->SetScale(Background_Scale);
	TitleReturn_->SetTranslate(TitleReturn_pos);
	TitleReturn_->SetScale(TitleReturn_scale);


	GameClerUI_->Update();
	TitleReturn_->Update();

	// 繝輔ぉ繝ｼ繝我ｸｭ縺ｯ繝励Ξ繧､繝､繝ｼ縺ｮ蜈･蜉帙ｒ蜿励￠莉倥￠縺ｪ縺・ｈ縺・↓縺吶ｋ
	if (BlackScreenTransition::GetInstance()->IsActive()) {
		return; // 縺薙％縺ｧ蜃ｦ逅・ｒ荳ｭ譁ｭ
	}

	if (input->PushBotton(XINPUT_GAMEPAD_B)|| input->PushKey(DIKEYBOARD_SPACE)) {
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
