#include "SelectUI.h"
#include "CLEYERA.h"

void SelectUI::Init() {
	const int selectCount = static_cast<int>(SelectItem::Count);
	SelectUI_.resize(selectCount);

	// �eUI�v�f�̐���
	SelectUI_[static_cast<int>(SelectItem::GameState)] = std::make_shared<SeletUI_GameState>();
	SelectUI_[static_cast<int>(SelectItem::Tutorial)] = std::make_shared<SeletUI_Tutorial>();
	SelectUI_[static_cast<int>(SelectItem::GameOver)] = std::make_shared<SeletUI_GameOver>();

	// ���O�̐ݒ�
	SelectUI_[0]->SetName(VAR_NAME(SeletUI_GameState));
	SelectUI_[1]->SetName(VAR_NAME(SeletUI_Tutorial));
	SelectUI_[2]->SetName(VAR_NAME(SeletUI_GameOver));

	for (auto& ui : SelectUI_) {
		ui->SetScale(Scale);
		ui->Init();
	}

	// �����ʒu�̐ݒ�
	for (int i = 0; i < selectCount; ++i) {
		// �ŏ��ɕ\�������̈ȊO�͉�ʊO�ɔz�u
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

	// �A�j���[�V�������łȂ��Ȃ�A���̓��͂�󂯕t����
	isChangeable_ = !SelectUI_[currentIndex_]->IsAnimating();  

#ifdef _DEBUG
	// ... (ImGui�̃R�[�h�͂��̂܂�)
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
	if (!isChangeable_) return; // �A�j���[�V�������͓��͂�󂯕t���Ȃ�

	const int itemCount = static_cast<int>(SelectItem::Count);
	int prevIndex = currentIndex_;

	// ���̃C���f�b�N�X��v�Z (0���������𒴂����烋�[�v������)
	currentIndex_ += direction;
	if (currentIndex_ < 0) {
		currentIndex_ = itemCount - 1;
	}
	else if (currentIndex_ >= itemCount) {
		currentIndex_ = 0;
	}

	// ���݂̑I�����X�V
	currentSelect_ = static_cast<SelectItem>(currentIndex_);

	// �A�j���[�V�����̊J�n
	// �Â�UI�͊O��
	Math::Vector::Vec2 slideOutTarget = (direction > 0) ? offScreenLeft_ : offScreenRight_;
	SelectUI_[prevIndex]->StartSlideAnimation(onScreenPos_, slideOutTarget);

	// �V����UI�͒���
	Math::Vector::Vec2 slideInStart = (direction > 0) ? offScreenRight_ : offScreenLeft_;
	SelectUI_[currentIndex_]->StartSlideAnimation(slideInStart, onScreenPos_);

	isChangeable_ = false; // アニメーション開始したので、一旦入力を無効化
}

void SelectUI::SetAllAlphas(float alpha){
	for (auto& ui : SelectUI_) {
		ui->SetAlpha(alpha);
	}
}
