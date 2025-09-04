#pragma once

#include "ITitleLogoUI.h"

class TitleLogo_WHITE :public ITitleLogo
{
public:
	TitleLogo_WHITE() = default;
	~TitleLogo_WHITE() = default;

	void Init() override {
		this->Create();
		this->GetJsonName();
		uint32_t handle = texManager_->LoadPngTex("TitleUI/whitebreath");
		handle_ = handle;
	}
	void Update() {
		sprite_->Update();
		WorldMatUpdate();
	}


};