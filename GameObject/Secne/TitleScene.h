#pragma once
#include "CLEYERA/CLEYERA.h"

#include "TitleUI/LogoUI/TitleLogo.h"
#include "TitleUI/SubUI/SubUI_Manager.h"
#include "TitleUI/SelectUI/SelectUI.h"


class TitleScene:public CLEYERA::Component::SceneComponent
{
public:

	enum class State {
		LOGO_SHOW,      // ���S�\�����i���͑҂��j
		LOGO_ANIMATING, // ���S���A�j���[�V������
		SELECT_ACTIVE   // �I����������\
	};

	TitleScene() {};

	~TitleScene() {};

	void Init() override;

	void Update(CLEYERA::Manager::SceneManager* ins) override;

	void Draw2d() override;

private:

	std::unique_ptr<TitleLog> LogoManager_ = nullptr;
	std::unique_ptr<SubUI> subManager_ = nullptr;
	std::unique_ptr<SelectUI> SelectManager_ = nullptr;

	State currentState_ = State::LOGO_SHOW;

};
