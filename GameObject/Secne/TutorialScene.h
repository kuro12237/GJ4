#pragma once
#include "CLEYERA.h"

#include "BlackScreenTransition.h"

#include "TutorialSceneUI/TutorialSceneUI.h"
#include "TitleReturn/TitleReturn.h"



class TutorialScene :public CLEYERA::Component::SceneComponent{

public:
	TutorialScene() {};
	~TutorialScene() {};

	void Init() override;

	void Update(CLEYERA::Manager::SceneManager* ins) override;

	void Draw2d() override;

private:
	bool shouldTransition = false;
	std::unique_ptr<TutorialSceneUI> TutorialSceneUI_ = nullptr;

	Math::Vector::Vec3 Background_pos = { 640.0f,355.0f };
	Math::Vector::Vec3 Background_Scale = { 1.1f,0.7f };

};


