#include "SelectUI.h"
#include "../../../../Engine/GameEngine/CLEYERA/pch/Pch.h"

void SelectUI::Init() {
	const int selectCount = static_cast<int>(SelectItem::Count);
	SelectUI_.resize(selectCount);

	// 各UI要素の生成
	SelectUI_[static_cast<int>(SelectItem::GameState)] = std::make_shared<SeletUI_GameState>();
	SelectUI_[static_cast<int>(SelectItem::Tutorial)] = std::make_shared<SeletUI_Tutorial>();
	SelectUI_[static_cast<int>(SelectItem::GameOver)] = std::make_shared<SeletUI_GameOver>();

	// 名前の設定
	SelectUI_[0]->SetName(VAR_NAME(SeletUI_GameState));
	SelectUI_[1]->SetName(VAR_NAME(SeletUI_Tutorial));
	SelectUI_[2]->SetName(VAR_NAME(SeletUI_GameEnd));

	for (auto& ui : SelectUI_) {
		ui->SetScale(Scale);
		ui->Init();
	}

	// 初期位置の設定
	for (int i = 0; i < selectCount; ++i) {
		// 最初に表示するもの以外は画面外に配置
		if (i == currentIndex_) {
			SelectUI_[i]->SetTranslate(onScreenPos_);
		}
		else {
			SelectUI_[i]->SetTranslate(offScreenRight_);
		}
	}
}

void SelectUI::Update()
{
	for (auto& ui : SelectUI_) {
		ui->Update();
	}

	// アニメーション中でないなら、次の入力を受け付ける
	isChangeable_ = !SelectUI_[currentIndex_]->IsAnimating();  

#ifdef _DEBUG
	// ... (ImGuiのコードはそのまま)
#endif // _DEBUG
}

void SelectUI::Draw2D()
{
	for (auto& ui : SelectUI_) {
		ui->Draw();
	}
}

void SelectUI::OnDpadInput(int direction)
{
	if (!isChangeable_) return; // アニメーション中は入力を受け付けない

	const int itemCount = static_cast<int>(SelectItem::Count);
	int prevIndex = currentIndex_;

	// 次のインデックスを計算 (0未満や上限を超えたらループさせる)
	currentIndex_ += direction;
	if (currentIndex_ < 0) {
		currentIndex_ = itemCount - 1;
	}
	else if (currentIndex_ >= itemCount) {
		currentIndex_ = 0;
	}

	// 現在の選択肢を更新
	currentSelect_ = static_cast<SelectItem>(currentIndex_);

	// アニメーションの開始
	// 古いUIは外へ
	Math::Vector::Vec2 slideOutTarget = (direction > 0) ? offScreenLeft_ : offScreenRight_;
	SelectUI_[prevIndex]->StartSlideAnimation(onScreenPos_, slideOutTarget);

	// 新しいUIは中へ
	Math::Vector::Vec2 slideInStart = (direction > 0) ? offScreenRight_ : offScreenLeft_;
	SelectUI_[currentIndex_]->StartSlideAnimation(slideInStart, onScreenPos_);

	isChangeable_ = false; // アニメーション開始したので、一旦入力を無効化
}