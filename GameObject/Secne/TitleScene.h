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
		FADING_IN,          // シーン開始時のフェードイン待ち
		LOGO_SHOW,			// ロゴ表示中（入力待ち）
		LOGO_ANIMATING,		// ロゴがアニメーション中
		SELECT_ACTIVE,		// 選択肢が操作可能
		WAITING_FOR_FADE_OUT, // フェードアウト完了待ち
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
	const float FADE_DURATION = 1.0f; // フェードにかける時間（1秒）
	std::string nextSceneName_ = "";    // 遷移先のシーン名を保持する変数
};
