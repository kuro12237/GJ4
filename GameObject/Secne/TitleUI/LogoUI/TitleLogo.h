#pragma once
#include "CLEYERA.h"

#include "ITitleLogoUI.h"
#include "TitleLogo_HOT.h"
#include "TitleLogo_WHITE.h"

#include "list"

class TitleLog
{
public:
	TitleLog() = default;
	~TitleLog() = default;

	void Init();
	void Update();
	void Draw2D();

private:
	std::vector<std::shared_ptr<ITitleLogo>> TitleLogo_;

	Math::Vector::Vec2 HOT_pos = { 650.0f,320.0f };
	Math::Vector::Vec2 WHITE_pos = { 650.0f,320.0f };
	Math::Vector::Vec2 Scale = { 0.5f,0.5f };
};

