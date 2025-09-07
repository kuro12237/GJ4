#pragma once
#include "../ISubUI.h"

class A_Button :public ISubUI
{
public:
	A_Button() = default;
	~A_Button() = default;

	void Init() override {
		this->Create();
		this->GetJsonName();
		uint32_t handle = texManager_->LoadPngTex("TitleUI/A_Botton");
		handle_ = handle;
	}
	void Update() {
		sprite_->Update();
		WorldMatUpdate();
	}


};