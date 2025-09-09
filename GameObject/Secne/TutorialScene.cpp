#include "TutorialScene.h"

void TutorialScene::Init(){
	// �ŏ��Ƀg�����W�V�����̏��������s��
	BlackScreenTransition::GetInstance()->Init();

	shouldTransition = false;


	BlackScreenTransition::GetInstance()->StartFadeIn(2.0f, [this]() {
		
		});
}

void TutorialScene::Update(CLEYERA::Manager::SceneManager* ins){

	// ���t���[���A�g�����W�V�����i�t�F�[�h�����j�̍X�V���Ăяo��
	BlackScreenTransition::GetInstance()->Update();

	auto input = CLEYERA::Manager::InputManager::GetInstance();
	auto sceneManager = CLEYERA::Manager::SceneManager::GetInstance();


	// �t�F�[�h���̓v���C���[�̓��͂��󂯕t���Ȃ��悤�ɂ���
	if (BlackScreenTransition::GetInstance()->IsActive()) {
		return; // �����ŏ����𒆒f
	}

	if (input->PushBotton(XINPUT_GAMEPAD_A)) {
		shouldTransition = true;
	}

	// �V�[���J�ڂ��K�v�ȏꍇ
	if (shouldTransition) {
		// �t�F�[�h�A�E�g���J�n
		BlackScreenTransition::GetInstance()->StartFadeOut(1.0f, [=]() {
			sceneManager->ChangeScene("TitleScene");
			return;
			});
	}
}

void TutorialScene::Draw2d(){
	BlackScreenTransition::GetInstance()->Draw2D();
}
