#pragma once
#include "CLEYERA.h"

#include "BlackScreenTransition.h"

class GameClear :public CLEYERA::Component::SceneComponent{
public:
	GameClear() {};
	~GameClear() {};

	void Init() override;

	void Update(CLEYERA::Manager::SceneManager* ins) override;

	void Draw2d() override;

private:
	bool shouldTransition = false;

};

