#pragma once
#include "CLEYERA/CLEYERA.h"

#include "TitleUI/LogoUI/TitleLogo.h"
#include "TitleUI/SubUI/SubUI_Manager.h"
#include "TitleUI/SelectUI/SelectUI.h"


class TitleScene:public CLEYERA::Component::SceneComponent
{
public:

	enum class State {
		LOGO_SHOW,      // ロゴ表示中（入力待ち）
		LOGO_ANIMATING, // ロゴがアニメーション中
		SELECT_ACTIVE   // 選択肢が操作可能
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
