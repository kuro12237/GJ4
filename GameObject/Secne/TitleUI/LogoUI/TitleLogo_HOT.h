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

		if (ImGui::TreeNode("TestSprite")) {

			this->TransformImGuiUpdate();
			ImGui::DragFloat2("size", &size_.x);
			ImGui::DragFloat4("color", &sprite_->ColorData().color_.x);

			ImGui::DragFloat2("LT", &this->LeftTop_.x, 0.01f, 0.0f, 1.0f);
			ImGui::DragFloat2("LB", &this->LeftBottom_.x, 0.01f, 0.0f, 1.0f);
			ImGui::DragFloat2("RT", &this->RightTop_.x, 0.01f, 0.0f, 1.0f);
			ImGui::DragFloat2("RB", &this->RightBottom_.x, 0.01f, 0.0f, 1.0f);


			ImGui::TreePop();

		}
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
