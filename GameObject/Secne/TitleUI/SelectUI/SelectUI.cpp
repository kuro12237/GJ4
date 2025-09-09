#include "SelectUI.h"
#include "CLEYERA.h"

void SelectUI::Init() {
	//タイトルロゴは二つ
	SelectUI_.resize(2);

	//HOTLIMIT(タイトルロゴ上)
	SelectUI_[0] = std::make_shared<SeletUI_GameState>();
	SelectUI_[0]->SetName(VAR_NAME(SeletUI_GameState));
	//WHITEBREATH(タイトルロゴ下)
	SelectUI_[1] = std::make_shared<SeletUI_Options>();
	SelectUI_[1]->SetName(VAR_NAME(SeletUI_Options));

	for (auto SelectUI : SelectUI_) {

		SelectUI->SetScale({ Scale });
		SelectUI->Init();
	}

	SelectUI_[0]->SetTranslate({ GameState_pos });

	SelectUI_[1]->SetTranslate({ Option_pos });

}

void SelectUI::Update()
{
	for (auto SelectUI : SelectUI_) {
		SelectUI->Update();
	}

	SelectUI_[0]->SetTranslate(GameState_pos);
	SelectUI_[1]->SetTranslate(Option_pos);

#ifdef _DEBUG

	if (ImGui::TreeNode("Log")) {


		ImGui::DragFloat2("size", &Scale.x);

		ImGui::DragFloat2("HOT_pos", &this->GameState_pos.x, 1.f, -1000.0f, 1000.0f);
		ImGui::DragFloat2("WHITE_pos", &this->Option_pos.x, 1.f, -1000.0f, 1000.0f);


		ImGui::TreePop();

	}

#endif // _DEBUG
}

void SelectUI::Draw2D()
{
	for (auto SelectUI : SelectUI_) {
		SelectUI->Draw();
	}
}
