#include "GameOverUI.h"

void GameOverUI::Init(){
	this->name_ = VAR_NAME(GameOverUI);

	this->Create();
	this->GetJsonName();
	uint32_t handle = texManager_->LoadPngTex("10days_gameOver");
	handle_ = handle;
}

void GameOverUI::Update(){


	sprite_->Update();
	WorldMatUpdate();
}
