#pragma once
#include "CLEYERA.h"
#include "GameClerUI/GameClerUI.h"
#include "BlackScreenTransition.h"
#include "TitleReturn/TitleReturn.h"

#include "Camera.h"


class GameClear :public CLEYERA::Component::SceneComponent{
public:
	GameClear() {};
	~GameClear() {};

	void Init() override;

	void Update(CLEYERA::Manager::SceneManager* ins) override;

	void Draw2d() override;

private:
	bool shouldTransition = false;

	std::unique_ptr<GameClerUI> GameClerUI_ = nullptr;
	std::unique_ptr<TitleReturn> TitleReturn_ = nullptr;
	std::shared_ptr<CameraUI> camera_ = nullptr;

	Math::Vector::Vec3 Background_pos = { 640.0f,355.0f };
	Math::Vector::Vec3 Background_Scale = { 1.0f,0.57f };

	Math::Vector::Vec3 TitleReturn_pos = { 1110.0f,85.0f };
	Math::Vector::Vec3 TitleReturn_scale = { 0.3f,0.2f };

	// ì_ñ≈èàóùópÇÃïœêî
	float blinkTimer_ = 0.0f;
	bool isTitleReturnVisible_ = true;
	const float BLINK_INTERVAL = 0.5f;
};

