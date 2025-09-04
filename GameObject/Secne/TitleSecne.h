#pragma once
#include "CLEYERA/CLEYERA.h"

class TitleScene:public CLEYERA::Component::SceneComponent
{
public:
	TitleScene() {};

	~TitleScene() {};

	void Init() override;

	void Update(CLEYERA::Manager::SceneManager* ins) override;

	void Draw2d() override;

private:



};



