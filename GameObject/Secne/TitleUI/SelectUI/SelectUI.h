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
		//Options, // �K�v�ł���Βǉ�
		Count // ���ڂ̑���
	};

	SelectUI() = default;
	~SelectUI() = default;

	void Init();
	void Update();
	void Draw2D();

	// �O��������͂��󂯎�邽�߂̊֐�
	void OnDpadInput(int direction);

	// ���ݑI�𒆂̍��ڂ�Ԃ��֐�
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
	bool isChangeable_ = true; // �A�Ŗh�~�t���O

	// ��ʓ��O�̍��W���`
	Math::Vector::Vec2 onScreenPos_ = { 640.0f, 350.0f }; // ��ʒ���
	Math::Vector::Vec2 offScreenLeft_ = { -300.0f, 350.0f }; // ��ʍ��O
	Math::Vector::Vec2 offScreenRight_ = { 1580.0f, 350.0f };// ��ʉE�O
};

