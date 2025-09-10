#pragma once

#include "IGamePlayStandbyUI.h"

class number_GO :public IGamePlayStandbyUI {
public:

	number_GO() = default;
	~number_GO() = default;

	void Init() override {
		this->Create();
		this->GetJsonName();
		//uint32_t handle = texManager_->LoadPngTex("TitleUI/hotlimit");
		uint32_t handle = texManager_->LoadPngTex("go");

		handle_ = handle;
	}

	void Update() {

		
		this->size_ = { 256,256 };
		IGamePlayStandbyUI::Update();
		sprite_->Update();
		WorldMatUpdate();


	}

};