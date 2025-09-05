#pragma once
#include "CLEYERA/CLEYERA.h"

#include "A_ButtonUI/A_Button.h"
#include "Background/Background.h"
#include "ControllerUI/Controller.h"

class SubUI
{
public:
	SubUI() = default;
	~SubUI() = default;

	enum class SubUI_Types {
		Background,
		A_Button,
		Controller,
	};


	void Init();
	void Update();
	void Draw2D();

private:
	std::vector<std::shared_ptr<ISubUI>> ISubUI_;

	Math::Vector::Vec2 Background_pos = { 640.0f,110.0f };
	Math::Vector::Vec2 Background_Scale = { 1.1f,1.0f };

	Math::Vector::Vec2 A_Button_pos = { 650.0f,600.0f };
	Math::Vector::Vec2 A_Button_Scale = { 0.5f,0.5f };

	Math::Vector::Vec2 Controller_pos = { 285.f,676.0f };
	Math::Vector::Vec2 Controller_Scale = { 1.f,0.7f };


};

