#pragma once
#include "CLEYERA.h"

#include "BlackScreenTransition.h"

#include "TutorialSceneUI/TutorialSceneUI.h"
#include "TitleReturn/TitleReturn.h"
#include "Camera.h"



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
	std::unique_ptr<TitleReturn> TitleReturn_ = nullptr;
	std::shared_ptr<CameraUI> camera_ = nullptr;


	Math::Vector::Vec3 Background_pos = { 640.0f,355.0f };
	Math::Vector::Vec3 Background_Scale = { 1.1f,0.7f };

	Math::Vector::Vec3 TitleReturn_pos = { 175.0f,40.0f };
	Math::Vector::Vec3 TitleReturn_scale = { 0.3f,0.2f };

	// �_�ŏ����p�̕ϐ�
	float blinkTimer_ = 0.0f;
	bool isTitleReturnVisible_ = true;
	const float BLINK_INTERVAL = 0.5f; // �_�ł̊Ԋu�i0.5�b���Ƃɐ؂�ւ��j

};


