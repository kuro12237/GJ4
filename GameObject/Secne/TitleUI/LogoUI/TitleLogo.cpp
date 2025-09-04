#include "TitleLogo.h"
#include "../../../../Engine/GameEngine/CLEYERA/pch/Pch.h"

void TitleLog::Init() {
	//タイトルロゴは二つ
	TitleLogo_.resize(2);

	//HOTLIMIT(タイトルロゴ上)
	TitleLogo_[0] = std::make_shared<TitleLogo_HOT>();
	TitleLogo_[0]->SetName(VAR_NAME(TitleLogo_HOT));
	//WHITEBREATH(タイトルロゴ下)
	TitleLogo_[1] = std::make_shared<TitleLogo_WHITE>();
	TitleLogo_[1]->SetName(VAR_NAME(TitleLogo_WHITE));

	for (auto Logo : TitleLogo_) {
		
		Logo->SetScale({ Scale });
		Logo->Init();
	}

	TitleLogo_[0]->SetTranslate({ HOT_pos });

	TitleLogo_[1]->SetTranslate({ WHITE_pos });

}

void TitleLog::Update()
{
	for (auto Logo : TitleLogo_) {
		Logo->Update();
	}

	TitleLogo_[0]->SetTranslate( HOT_pos);
	TitleLogo_[1]->SetTranslate(WHITE_pos);

#ifdef _DEBUG

	if (ImGui::TreeNode("Log")) {

		
		ImGui::DragFloat2("size", &Scale.x);
		
		ImGui::DragFloat2("HOT_pos", &this->HOT_pos.x, 1.f, -1000.0f, 1000.0f);
		ImGui::DragFloat2("WHITE_pos", &this->WHITE_pos.x, 1.f, -1000.0f, 1000.0f);


		ImGui::TreePop();

	}

#endif // _DEBUG
}

void TitleLog::Draw2D()
{
	for (auto Logo : TitleLogo_) {
		Logo->Draw();
	}
}
