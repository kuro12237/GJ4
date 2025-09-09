#pragma once
#include "CLEYERA.h"

#include "ISelectUI.h"
#include "SeletUI_GameState.h"
#include "SeletUI_Options.h"

#include "list"

class SelectUI
{
public:
	SelectUI() = default;
	~SelectUI() = default;

	void Init();
	void Update();
	void Draw2D();

private:
	std::vector<std::shared_ptr<ISelectUI>> SelectUI_;

	Math::Vector::Vec2 GameState_pos = { 650.0f,320.0f };
	Math::Vector::Vec2 Option_pos = { 650.0f,320.0f };
	Math::Vector::Vec2 Scale = { 0.5f,0.5f };
};

