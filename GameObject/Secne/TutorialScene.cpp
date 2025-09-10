#include "TutorialScene.h"

void TutorialScene::Init(){
	// �ŏ��Ƀg�����W�V�����̏��������s��
	BlackScreenTransition::GetInstance()->Init();

	shouldTransition = false;


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

	//�e�V�[���ŌĂяo��
	if (BlackScreenTransition::GetInstance()->isOverReturn()) {
		return;
	}

	// �t�F�[�h���̓v���C���[�̓��͂��󂯕t���Ȃ��悤�ɂ���
	if (BlackScreenTransition::GetInstance()->IsActive()) {
		return; // �����ŏ����𒆒f
	}

	if (input->PushBotton(XINPUT_GAMEPAD_A)) {
		shouldTransition = true;
	}

}

void TutorialScene::Draw2d(){
	BlackScreenTransition::GetInstance()->Draw2D();
}
