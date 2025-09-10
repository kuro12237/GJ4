#pragma once

class GameManager {
public:
    // ���̃N���X�̗B��̃C���X�^���X���擾����
    static GameManager* GetInstance();

    // �Q�[���I�������N�G�X�g����
    void RequestQuit() { isQuitRequested_ = true; }

    // �Q�[�����I�������N�G�X�g����Ă��邩�m�F����
    bool IsQuitRequested() const { return isQuitRequested_; }

private:
    // �V���O���g���ɂ��邽�߁A�R���X�g���N�^�Ȃǂ�private�ɂ���
    GameManager() = default;
    ~GameManager() = default;
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;

    bool isQuitRequested_ = false;
};