#pragma once
#include "CLEYERA.h"

#include "BlackScreenTransition.h"


class TutorialScene :public CLEYERA::Component::SceneComponent{

public:
	TutorialScene() {};
	~TutorialScene() {};

	void Init() override;

	void Update(CLEYERA::Manager::SceneManager* ins) override;

	void Draw2d() override;

private:
	bool shouldTransition = false;

};


