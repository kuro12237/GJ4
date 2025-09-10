#pragma once
#include "CLEYERA.h"
#include "BlackScreenTransition.h"
#include "GameOverUI/GameOverUI.h"
#include "TitleReturn/TitleReturn.h"

class GameOver :public CLEYERA::Component::SceneComponent{
public:
	GameOver() {};
	~GameOver() {};
	
	void Init() override;

	void Update(CLEYERA::Manager::SceneManager* ins) override;

	void Draw2d() override;

private:
	bool shouldTransition = false;
	std::unique_ptr<GameOverUI> GameOverUI_ = nullptr;
	std::unique_ptr<TitleReturn> TitleReturn_ = nullptr;


	Math::Vector::Vec3 Background_pos = { 640.0f,355.0f };
	Math::Vector::Vec3 Background_Scale = { 1.1f,0.7f };

	Math::Vector::Vec3 TitleReturn_pos = { 650.0f,620.0f };
	Math::Vector::Vec3 TitleReturn_scale = { 0.3f,0.2f };
};

