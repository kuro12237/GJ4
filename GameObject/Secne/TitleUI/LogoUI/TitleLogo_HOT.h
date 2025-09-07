#pragma once

#include "ITitleLogoUI.h"

class TitleLogo_HOT:public ITitleLogo
{
public:
	TitleLogo_HOT() = default;
	~TitleLogo_HOT() = default;

	void Init() override {
		this->Create();
		this->GetJsonName();
		uint32_t handle = texManager_->LoadPngTex("TitleUI/hotlimit");
		handle_ = handle;
	}
	void Update() {
		ITitleLogo::Update();
		sprite_->Update();
		WorldMatUpdate();
	}




};
