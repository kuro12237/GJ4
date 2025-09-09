#pragma once
#include "CLEYERA.h"

#include "TitleUI/LogoUI/TitleLogo.h"
#include "TitleUI/SubUI/SubUI_Manager.h"
#include "TitleUI/SelectUI/SelectUI.h"
#include "BlackScreenTransition.h"


class TitleScene:public CLEYERA::Component::SceneComponent
{
public:

	enum class State {
		FADING_IN,          // �V�[���J�n���̃t�F�[�h�C���҂�
		LOGO_SHOW,			// ���S�\�����i���͑҂��j
		LOGO_ANIMATING,		// ���S���A�j���[�V������
		SELECT_ACTIVE,		// �I����������\
		WAITING_FOR_FADE_OUT, // �t�F�[�h�A�E�g�����҂�
	};

	TitleScene() {};

	~TitleScene();

	void Init() override;

	void Update(CLEYERA::Manager::SceneManager* ins) override;

	void Draw2d() override;

private:

	std::unique_ptr<TitleLog> LogoManager_ = nullptr;
	std::unique_ptr<SubUI> subManager_ = nullptr;
	std::unique_ptr<SelectUI> SelectManager_ = nullptr;

	State currentState_ = State::LOGO_SHOW;

	float fadeTimer_ = 0.0f;
	const float FADE_DURATION = 1.0f; // �t�F�[�h�ɂ����鎞�ԁi1�b�j
	std::string nextSceneName_ = "";    // �J�ڐ�̃V�[������ێ�����ϐ�
};
