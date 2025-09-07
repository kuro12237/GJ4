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

	void StartOpeningAnimation(float distance, float duration);
	bool IsAnimating() const;

private:
	std::vector<std::shared_ptr<ITitleLogo>> TitleLogo_;

	Math::Vector::Vec2 HOT_pos = { 650.0f,330.0f };//y=290ˆÚ“®Œã
	Math::Vector::Vec2 WHITE_pos = { 650.0f,330.0f };//y=370ˆÚ“®Œã
	Math::Vector::Vec2 Scale = { 0.6f,0.4f };
};

