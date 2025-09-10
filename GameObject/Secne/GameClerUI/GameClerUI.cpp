#include "GameClerUI.h"

void GameClerUI::Init(){
	this->name_ = VAR_NAME(GameOverUI);

	this->Create();
	this->GetJsonName();
	uint32_t handle = texManager_->LoadPngTex("clear");
	handle_ = handle;
}

void GameClerUI::Update(){
	sprite_->Update();
	WorldMatUpdate();
}
