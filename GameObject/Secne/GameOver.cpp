#include "GameOver.h"

void GameOver::Init() {
	// �ŏ��Ƀg�����W�V�����̏��������s��
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


	// �V�[���J�ڂ��K�v�ȏꍇ
	if (shouldTransition) {
		// �t�F�[�h�A�E�g���J�n
		BlackScreenTransition::GetInstance()->StartFadeOut(1.0f, [=]() {
			sceneManager->ChangeScene("TitleScene");
			return;
			});
	}
	// ���t���[���A�g�����W�V�����i�t�F�[�h�����j�̍X�V���Ăяo��
	BlackScreenTransition::GetInstance()->Update();

	//�e�V�[���ŌĂяo��
	if (BlackScreenTransition::GetInstance()->isOverReturn()){
		return;
	}

#ifdef _DEBUG

	if (ImGui::TreeNode("GameOver")) {
		ImGui::DragFloat2("Background_Scale", &Background_Scale.x);
		ImGui::DragFloat2("Background_pos", &this->Background_pos.x, 1.f, -1000.0f, 1000.0f);
		ImGui::DragFloat2("TitleReturn_scale", &TitleReturn_scale.x);
		ImGui::DragFloat2("TitleReturn_pos", &this->TitleReturn_pos.x, 1.f, -1000.0f, 1000.0f);

		ImGui::TreePop();
	}

#endif	_DEBUG

	GameOverUI_->SetTranslate(Background_pos);
	GameOverUI_->SetScale(Background_Scale);
	TitleReturn_->SetTranslate(TitleReturn_pos);
	TitleReturn_->SetScale(TitleReturn_scale);


	GameOverUI_->Update();
	TitleReturn_->Update();

	// �t�F�[�h���̓v���C���[�̓��͂��󂯕t���Ȃ��悤�ɂ���
	if (BlackScreenTransition::GetInstance()->IsActive()) {
		return;
	}

	if (input->PushBotton(XINPUT_GAMEPAD_B)) {
		shouldTransition = true;
	}

}

void GameOver::Draw2d() {

	GameOverUI_->Draw();
	TitleReturn_->Draw();

	BlackScreenTransition::GetInstance()->Draw2D();

}
