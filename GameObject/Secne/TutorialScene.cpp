#include "TutorialScene.h"

void TutorialScene::Init(){
	// �ŏ��Ƀg�����W�V�����̏��������s��
	BlackScreenTransition::GetInstance()->Init();

	shouldTransition = false;

	camera_ = std::make_shared<CameraUI>();
	camera_->Init();

	TutorialSceneUI_ = std::make_unique<TutorialSceneUI>();
	TutorialSceneUI_->Init();
	TutorialSceneUI_->SetTranslate(Background_pos);
	TutorialSceneUI_->SetScale(Background_Scale);

	TitleReturn_ = std::make_unique<TitleReturn>();
	TitleReturn_->Init();
	TitleReturn_->SetTranslate(Background_pos);
	TitleReturn_->SetScale(Background_Scale);

	BlackScreenTransition::GetInstance()->StartFadeIn(2.0f, [this]() {
		
		});
}

void TutorialScene::Update(CLEYERA::Manager::SceneManager* ins){

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

	// �_�Ń^�C�}�[�̍X�V
	const float DELTA_TIME_60FPS = 1.0f / 60.0f;
	blinkTimer_ += DELTA_TIME_60FPS;

	// �w�肵�����Ԃ��o�߂�����
	if (blinkTimer_ >= BLINK_INTERVAL) {
		isTitleReturnVisible_ = !isTitleReturnVisible_; // �\���t���O�𔽓]������ (true -> false, false -> true)
		blinkTimer_ = 0.0f; // �^�C�}�[�����Z�b�g
	}

	//�e�V�[���ŌĂяo��
	if (BlackScreenTransition::GetInstance()->isOverReturn()) {
		return;
	}

	TutorialSceneUI_->SetTranslate(Background_pos);
	TutorialSceneUI_->SetScale(Background_Scale);

	TitleReturn_->SetTranslate(TitleReturn_pos);
	TitleReturn_->SetScale(TitleReturn_scale);


	TutorialSceneUI_->Update();
	TitleReturn_->Update();
	// �t�F�[�h���̓v���C���[�̓��͂��󂯕t���Ȃ��悤�ɂ���
	if (BlackScreenTransition::GetInstance()->IsActive()) {
		return; // �����ŏ����𒆒f
	}

	if (input->PushBotton(XINPUT_GAMEPAD_B)) {
		shouldTransition = true;
	}

}

void TutorialScene::Draw2d(){
	TutorialSceneUI_->Draw();
	if (isTitleReturnVisible_) {
		TitleReturn_->Draw();
	}
	BlackScreenTransition::GetInstance()->Draw2D();
}
