#include "TutorialSceneUI.h"

void TutorialSceneUI::Init(){
	this->name_ = VAR_NAME(GameOverUI);

	this->Create();
	this->GetJsonName();
	uint32_t handle = texManager_->LoadPngTex("10days_gameOver");
	handle_ = handle;
}

void TutorialSceneUI::Update(){
	sprite_->Update();
	WorldMatUpdate();
}
