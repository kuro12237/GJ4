#pragma once
#include "../ISubUI.h"

class ControllerUI :public ISubUI
{
public:
	ControllerUI() = default;
	~ControllerUI() = default;

	void Init() override {
		this->Create();
		this->GetJsonName();
		uint32_t handle = texManager_->LoadPngTex("TitleUI/Controller");
		handle_ = handle;
	}
	void Update() {
		sprite_->Update();
		WorldMatUpdate();
	}


};