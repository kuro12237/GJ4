#pragma once

#include "IGamePlayStandbyUI.h"

class number_3 :public IGamePlayStandbyUI {
public:

	number_3() = default;
	~number_3() = default;

	void Init() override {
		this->Create();
		this->GetJsonName();
		//uint32_t handle = texManager_->LoadPngTex("TitleUI/hotlimit");
		uint32_t handle = texManager_->LoadPngTex("numbers");

		handle_ = handle;
	}

	void Update() {

		this->LeftTop_.x = 0.3;
		this->LeftBottom_.x = 0.3;
		this->RightTop_.x = 0.4;
		this->RightBottom_.x = 0.4;
		this->size_ = { 256,256 };
		IGamePlayStandbyUI::Update();
		sprite_->Update();
		WorldMatUpdate();


	}

};