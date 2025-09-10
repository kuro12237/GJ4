#pragma once

#include "ITitleLogoUI.h"

class TitleLogo_HOT :public ITitleLogo
{
public:
	TitleLogo_HOT() = default;
	~TitleLogo_HOT() = default;

	void Init() override {
		this->Create();
		this->GetJsonName();
		uint32_t handle = texManager_->LoadPngTex("TitleUI/hotlimit");
		//uint32_t handle = texManager_->LoadPngTex("numbers");

		handle_ = handle;
	}
	void Update() {


		/*this->RightBottom_.x = 0.1;
		this->RightTop_.x = 0.1;
		this->LeftTop_.x = 0.1;
		this->LeftBottom_.x = 0.1;
		this->size_ = { 256,256 };*/
		ITitleLogo::Update();
		sprite_->Update();
		WorldMatUpdate();


	}

};
