#include "TitleSecne.h"

void TitleScene::Init()
{
	uiManager_ = std::make_unique<TitleLog>();
	uiManager_->Init();

	subManager_ = std::make_unique<SubUI>();
	subManager_->Init();

}

void TitleScene::Update([[maybe_un_used]]CLEYERA::Manager::SceneManager* ins){

	auto input = CLEYERA::Manager::InputManager::GetInstance();
	//十字キー上
	if (input->PushBotton(XINPUT_GAMEPAD_DPAD_UP)) {
	
	}
	//十字キー下
	if (input->PushBotton(XINPUT_GAMEPAD_DPAD_DOWN)) {

	}

	uiManager_->Update();
	subManager_->Update();
}

void TitleScene::Draw2d(){

	uiManager_->Draw2D();
	subManager_->Draw2D();
}
