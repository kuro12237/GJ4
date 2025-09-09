#include "GamePlayStandbyUI.h"

void GamePlayStandbyUI::Init()
{
	// 4��UI�v�f�i3, 2, 1, GO�j�𐶐�
	StandbyUI_.resize(4);
	StandbyUI_[0] = std::make_shared<number_3>();
	StandbyUI_[1] = std::make_shared<number_2>();
	StandbyUI_[2] = std::make_shared<number_1>();
	StandbyUI_[3] = std::make_shared<number_GO>();

	// �S�Ă�UI�v�f�ɋ��ʂ̐ݒ��K�p
	for (auto& ui : StandbyUI_) {
		ui->Init();
		ui->SetScale(scale_);
		ui->SetTranslate(pos_); 
		ui->SetVisible(false);  
	}

	//StandbyUI_[3]->SetScale{(GO_Scale)};
	StandbyUI_[3]->SetScale(GO_Scale);
}

void GamePlayStandbyUI::Start(std::function<void()> on_finished)
{
	if (currentState_ != State::Idle) return;

	onFinishedCallback_ = on_finished;
	stateTimer_ = 0.0f;
	currentUiIndex_ = 0; // �ŏ���UI�́u3�v (�C���f�b�N�X0)
	currentState_ = State::Countdown;

	// �ŏ���UI�̃A�j���[�V�������J�n
	StandbyUI_[currentUiIndex_]->StartAnimation(0.8f, 1.2f, DURATION_PER_NUMBER);
}

void GamePlayStandbyUI::Update()
{
	// �J�E���g�_�E�����łȂ���Ή������Ȃ�
	if (currentState_ != State::Countdown) {
		return;
	}

	// �S�Ă�UI�v�f��Update���Ăяo���i�A�j���[�V�����v�Z�̂��߁j
	for (auto& ui : StandbyUI_) {
		ui->Update();
	}

	const float DELTA_TIME_60FPS = 1.0f / 60.0f;
	stateTimer_ += DELTA_TIME_60FPS;

	// 1�b�o�߂�����A���̐�����
	if (stateTimer_ >= DURATION_PER_NUMBER) {
		stateTimer_ = 0.0f; // �^�C�}�[���Z�b�g

		// ����UI���\���ɂ���
		StandbyUI_[currentUiIndex_]->SetVisible(false);

		// ����UI�փC���f�b�N�X��i�߂�
		currentUiIndex_++;

		// �����Ō��UI("GO")���I�������
		if (currentUiIndex_ >= StandbyUI_.size()) {
			currentState_ = State::Finished;
			if (onFinishedCallback_) {
				onFinishedCallback_(); // �Q�[���X�^�[�g�������Ăяo��
			}
		}
		//�܂��\������UI���c���Ă���Ȃ�
		else {
			// ����UI�̃A�j���[�V�������J�n
			StandbyUI_[currentUiIndex_]->StartAnimation(0.8f, 1.2f, DURATION_PER_NUMBER);
		}
	}
}

void GamePlayStandbyUI::Draw2d()
{
	// �S�Ă�UI�v�f�̕`�揈�����Ă�
	// �\�����(isVisible_)�͊eUI�������Ă���̂ŁA�\�����ׂ����̂������`�悳���
	for (auto& ui : StandbyUI_) {
		ui->Draw();
	}
}