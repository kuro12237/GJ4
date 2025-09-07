#pragma once
#include "ISelectUI.h"

class SeletUI_GameOver :public ISelectUI
{
public:
	SeletUI_GameOver() = default;
	~SeletUI_GameOver() = default;

	void Init() override {
		this->Create();
		this->GetJsonName();
		uint32_t handle = texManager_->LoadPngTex("TitleUI/GameOut");
		handle_ = handle;
	}
	void Update() {
		sprite_->Update();
		WorldMatUpdate();
	}


};