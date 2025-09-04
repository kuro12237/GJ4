#pragma once
#include "../ISubUI.h"

class Background :public ISubUI
{
public:
	Background() = default;
	~Background() = default;

	void Init() override {
		this->Create();
		this->GetJsonName();
		uint32_t handle = texManager_->LoadPngTex("TitleUI/Background");
		handle_ = handle;
	}
	void Update() {
		sprite_->Update();
		WorldMatUpdate();
	}


};