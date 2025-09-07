#pragma once

#include "ISelectUI.h"

class SeletUI_Options :public ISelectUI
{
public:
	SeletUI_Options() = default;
	~SeletUI_Options() = default;

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