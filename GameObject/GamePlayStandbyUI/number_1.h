#pragma once

#include "IGamePlayStandbyUI.h"

class number_1 :public IGamePlayStandbyUI {
public:

	number_1() = default;
	~number_1() = default;

	void Init() override {
		this->Create();
		this->GetJsonName();
		//uint32_t handle = texManager_->LoadPngTex("TitleUI/hotlimit");
		uint32_t handle = texManager_->LoadPngTex("numbers");

		handle_ = handle;
	}

	void Update() {
	
		this->LeftTop_.x = 0.1;
		this->LeftBottom_.x = 0.1;
		this->RightTop_.x = 0.2;
		this->RightBottom_.x = 0.2;
		this->size_ = { 256,256 };
		IGamePlayStandbyUI::Update();
		sprite_->Update();
		WorldMatUpdate();


	}

};