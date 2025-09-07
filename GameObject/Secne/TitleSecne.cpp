#include "TitleSecne.h"

void TitleScene::Init()
{
	LogoManager_ = std::make_unique<TitleLog>();
	LogoManager_->Init();

	subManager_ = std::make_unique<SubUI>();
	subManager_->Init();

}

void TitleScene::Update([[maybe_un_used]]CLEYERA::Manager::SceneManager* ins){

	auto input = CLEYERA::Manager::InputManager::GetInstance();
	//十字キー上
	if (input->PushBotton(XINPUT_GAMEPAD_DPAD_RIGHT)) {
	
	}
	//十字キー下
	if (input->PushBotton(XINPUT_GAMEPAD_DPAD_LEFT)) {

	}

	//Aボタン
	if (input->PushBotton(XINPUT_GAMEPAD_A)) {

	}

	LogoManager_->Update();
	subManager_->Update();
}

void TitleScene::Draw2d(){

	subManager_->Draw2D();
	LogoManager_->Draw2D();
}
