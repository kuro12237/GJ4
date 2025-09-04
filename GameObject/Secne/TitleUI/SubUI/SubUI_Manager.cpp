#include "SubUI_Manager.h"

void SubUI::Init(){
	//UIÇÃê∂ê¨
	ISubUI_.resize(3);
	ISubUI_[int(SubUI_Types::Background)]= std::make_shared<Background>();

	//UIÇÃê›íË
	ISubUI_[int(SubUI_Types::Background)]->SetName(VAR_NAME(Background));
	ISubUI_[int(SubUI_Types::Background)]->SetTranslate({ Background_pos });
	ISubUI_[int(SubUI_Types::Background)]->SetScale({ Background_Scale });

	for (auto ISubUI : ISubUI_) {
		ISubUI->Init();
	}
}

void SubUI::Update(){
	for (auto ISubUI : ISubUI_) {
		ISubUI->Update();
	}
	ISubUI_[int(SubUI_Types::Background)]->SetTranslate({ Background_pos });
	ISubUI_[int(SubUI_Types::Background)]->SetScale({ Background_Scale });

#ifdef _DEBUG

	if (ImGui::TreeNode("SubUI")) {

		ImGui::DragFloat2("size", &Background_Scale.x);
		ImGui::DragFloat2("Background_pos", &this->Background_pos.x, 1.f, -1000.0f, 1000.0f);


		ImGui::TreePop();

	}

#endif // _DEBUG

}

void SubUI::Draw2D(){
	for (auto ISubUI : ISubUI_) {
		ISubUI->Draw();
	}
}
