#include "Operation.h"

void Operation::Init(){
	this->name_ = VAR_NAME(GameOverUI);

	this->Create();
	this->GetJsonName();
	uint32_t handle = texManager_->LoadPngTex("attackUi");
	handle_ = handle;

	this->scale_ = { 0.15f, 0.15f, 0.1f };
	translate_ = { 1140.0f, 600.0f, 0.0f };
}

void Operation::Update(){


	sprite_->Update();
	WorldMatUpdate();
}
