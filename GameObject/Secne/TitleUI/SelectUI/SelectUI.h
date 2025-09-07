#pragma once
#include "CLEYERA/CLEYERA.h"

#include "ISelectUI.h"
#include "SeletUI_GameState.h"
#include "SeletUI_Tutorial.h"
#include "SeletUI_GameOver.h"

#include "list"

class SelectUI
{
public:
	enum class SelectItem {
		GameState,
		Tutorial,
		GameOver,
		//Options, // 必要であれば追加
		Count // 項目の総数
	};

	SelectUI() = default;
	~SelectUI() = default;

	void Init();
	void Update();
	void Draw2D();

	// 外部から入力を受け取るための関数
	void OnDpadInput(int direction);

	// 現在選択中の項目を返す関数
	SelectItem GetCurrentSelect() const { return currentSelect_; }

private:
	void ChangeSelection(int newIndex, int direction);

private:
	std::vector<std::shared_ptr<ISelectUI>> SelectUI_;

	//Math::Vector::Vec2 GameState_pos = { 650.0f,320.0f };
	//Math::Vector::Vec2 Tutorial_pos = { 650.0f,320.0f };
	//Math::Vector::Vec2 GameOver_pos = { 650.0f,320.0f };
	Math::Vector::Vec2 Scale = { 0.5f,0.5f };

	SelectItem currentSelect_ = SelectItem::GameState;
	int currentIndex_ = 0;
	bool isChangeable_ = true; // 連打防止フラグ

	// 画面内外の座標を定義
	Math::Vector::Vec2 onScreenPos_ = { 640.0f, 350.0f }; // 画面中央
	Math::Vector::Vec2 offScreenLeft_ = { -300.0f, 350.0f }; // 画面左外
	Math::Vector::Vec2 offScreenRight_ = { 1580.0f, 350.0f };// 画面右外
};

