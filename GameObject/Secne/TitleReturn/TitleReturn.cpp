#include "TitleReturn.h"

void TitleReturn::Init(){
	this->name_ = VAR_NAME(TitleReturn);

	this->Create();
	this->GetJsonName();
	uint32_t handle = texManager_->LoadPngTex("");
	handle_ = handle;
}

void TitleReturn::Update(){
	sprite_->Update();
	WorldMatUpdate();
}
