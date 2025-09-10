#pragma once
#include "CLEYERA.h"


class GameOverUI :public SpriteComponent
{
public:
	GameOverUI() = default;
	~GameOverUI() = default;

	void Init() override;

	void Update() override;

private:
	//Math::Vector::Vec2 Background_pos = { 640.0f,110.0f };
	//Math::Vector::Vec2 Background_Scale = { 1.0f,1.0f };

};