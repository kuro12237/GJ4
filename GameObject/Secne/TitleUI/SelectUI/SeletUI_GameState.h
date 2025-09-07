#pragma once

#include "ISelectUI.h"

class SeletUI_GameState :public ISelectUI
{
public:
	SeletUI_GameState() = default;
	~SeletUI_GameState() = default;

	void Init() override {
		this->Create();
		this->GetJsonName();
		uint32_t handle = texManager_->LoadPngTex("TitleUI/GameState");
		handle_ = handle;
	}
	void Update() {
		ISelectUI::Update();
		sprite_->Update();
		WorldMatUpdate();
	}


};