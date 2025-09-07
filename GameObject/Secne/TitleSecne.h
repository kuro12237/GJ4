#pragma once
#include "CLEYERA/CLEYERA.h"

#include "TitleUI/LogoUI/TitleLogo.h"
#include "TitleUI/SubUI/SubUI_Manager.h"


class TitleScene:public CLEYERA::Component::SceneComponent
{
public:
	TitleScene() {};

	~TitleScene() {};

	void Init() override;

	void Update(CLEYERA::Manager::SceneManager* ins) override;

	void Draw2d() override;

private:

	std::unique_ptr<TitleLog> LogoManager_ = nullptr;
	std::unique_ptr<SubUI> subManager_ = nullptr;

};



