#pragma once
#include "CLEYERA.h"
#include "BlackScreenTransition.h"
#include "GameOverUI/GameOverUI.h"

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
};

