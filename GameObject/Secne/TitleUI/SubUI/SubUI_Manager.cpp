#include "SubUI_Manager.h"

void SubUI::Init(){
	//UIÇÃê∂ê¨
	ISubUI_.resize(3);
	ISubUI_[int(SubUI_Types::Background)]= std::make_shared<Background>();
	ISubUI_[int(SubUI_Types::A_Button)] = std::make_shared<A_Button>();
	ISubUI_[int(SubUI_Types::Controller)] = std::make_shared<ControllerUI>();

	//UIÇÃê›íË
	ISubUI_[int(SubUI_Types::Background)]->SetName(VAR_NAME(Background));
	ISubUI_[int(SubUI_Types::Background)]->SetTranslate({ Background_pos });
	ISubUI_[int(SubUI_Types::Background)]->SetScale({ Background_Scale });

	ISubUI_[int(SubUI_Types::A_Button)]->SetName(VAR_NAME(A_Button));
	ISubUI_[int(SubUI_Types::A_Button)]->SetTranslate({ A_Button_pos });
	ISubUI_[int(SubUI_Types::A_Button)]->SetScale({ A_Button_Scale });


	ISubUI_[int(SubUI_Types::Controller)]->SetName(VAR_NAME(ControllerUI));
	ISubUI_[int(SubUI_Types::Controller)]->SetTranslate({ Controller_pos });
	ISubUI_[int(SubUI_Types::Controller)]->SetScale({ Controller_Scale });

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

	ISubUI_[int(SubUI_Types::A_Button)]->SetTranslate({ A_Button_pos });
	ISubUI_[int(SubUI_Types::A_Button)]->SetScale({ A_Button_Scale });

	ISubUI_[int(SubUI_Types::Controller)]->SetTranslate({ Controller_pos });
	ISubUI_[int(SubUI_Types::Controller)]->SetScale({ Controller_Scale });


	auto input = CLEYERA::Manager::InputManager::GetInstance();

#ifdef _DEBUG

	if (ImGui::TreeNode("SubUI")) {

		ImGui::DragFloat2("Background_Scale", &Background_Scale.x);
		ImGui::DragFloat2("Background_pos", &this->Background_pos.x, 1.f, -1000.0f, 1000.0f);


		ImGui::DragFloat2("A_Button_Scale", &A_Button_Scale.x);
		ImGui::DragFloat2("A_Button_pos", &this->A_Button_pos.x, 1.f, -1000.0f, 1000.0f);

		ImGui::DragFloat2("Controller_Scale", &Controller_Scale.x);
		ImGui::DragFloat2("Controller_pos", &this->Controller_pos.x, 1.f, -1000.0f, 1000.0f);


		ImGui::TreePop();

	}

#endif // _DEBUG

}

void SubUI::Draw2D(){
	for (auto ISubUI : ISubUI_) {
		ISubUI->Draw();
	}
}
