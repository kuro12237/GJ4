#pragma once

#include "ISelectUI.h"

class SeletUI_Tutorial :public ISelectUI
{
public:
	SeletUI_Tutorial() = default;
	~SeletUI_Tutorial() = default;

	void Init() override {
		this->Create();
		this->GetJsonName();
		uint32_t handle = texManager_->LoadPngTex("TitleUI/Tutorial");
		handle_ = handle;
	}
	void Update() {
		sprite_->Update();
		WorldMatUpdate();
	}


};