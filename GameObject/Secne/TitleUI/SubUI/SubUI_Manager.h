#pragma once
#include "CLEYERA/CLEYERA.h"

//#include "A_ButtonUI/"
#include "Background/Background.h"
//#include "ControllerUI/"

class SubUI
{
public:
	SubUI() = default;
	~SubUI() = default;

	enum class SubUI_Types {
		A_Button,
		Background,
		Controller,
	};


	void Init();
	void Update();
	void Draw2D();

private:
	std::vector<std::shared_ptr<ISubUI>> ISubUI_;

	Math::Vector::Vec2 Background_pos = { 0.0f,0.0f };
	Math::Vector::Vec2 Background_Scale = { 1.0f,1.0f };

	Math::Vector::Vec2 A_Button_pos = { 650.0f,240.0f };
	Math::Vector::Vec2 A_Button_Scale = { 1.0f,1.0f };

	Math::Vector::Vec2 Controller_pos = { 0.0f,820.0f };
	Math::Vector::Vec2 Controller_Scale = { 1.0f,1.0f };


};

