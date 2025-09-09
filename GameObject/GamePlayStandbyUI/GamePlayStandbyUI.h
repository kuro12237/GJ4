#pragma once
#include "CLEYERA.h" // �G���W���̊�{�w�b�_
#include "IGamePlayStandbyUI.h"
#include "number_3.h"
#include "number_2.h"
#include "number_1.h"
#include "number_GO.h"
#include <vector>
#include <memory>
#include <functional>

class GamePlayStandbyUI
{
public:
	GamePlayStandbyUI() {};
	~GamePlayStandbyUI() {};

	void Init();
	void Update();
	void Draw2d();

	// �J�E���g�_�E���V�[�P���X���J�n����
	void Start(std::function<void()> on_finished);

	// �V�[�P���X�������������ǂ�����Ԃ�
	bool IsFinished() const { return currentState_ == State::Finished; }

private:
	enum class State {
		Idle,       // �J�n�҂�
		Countdown,  // �J�E���g�_�E�����s��
		Finished    // �S�Ċ���
	};

	State currentState_ = State::Idle;

	// ���������� SelectUI�̍\���������Ɏ������ ����������
	// UI�v�f��ێ�����x�N�^�[
	std::vector<std::shared_ptr<IGamePlayStandbyUI>> StandbyUI_;

	// UI�̍��W�ƃX�P�[�����Ǘ�����ϐ�
	Math::Vector::Vec3 pos_ = { 1280.0f / 2.0f, 720.0f / 2.0f }; // ��ʒ���
	Math::Vector::Vec3 scale_ = { 1.0f, 1.0f };

	Math::Vector::Vec3 GO_Scale = { 4.f,4.f };


	int currentUiIndex_ = -1; // ���ݕ\������UI�̃C���f�b�N�X
	float stateTimer_ = 0.0f; // �o�ߎ��Ԃ��v��^�C�}�[
	const float DURATION_PER_NUMBER = 1.0f; // 1�̐�����\�����鎞��

	std::function<void()> onFinishedCallback_;
};