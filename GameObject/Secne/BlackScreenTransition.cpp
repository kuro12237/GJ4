#include "BlackScreenTransition.h"
#include <algorithm> // std::max, std::min �̂��߂ɒǉ�

BlackScreenTransition* BlackScreenTransition::GetInstance() {
    static BlackScreenTransition instance;
    return &instance;
}

void BlackScreenTransition::Init() {
    // ���ɏ������ς݂̏ꍇ�͉������Ȃ�
    if (this->sprite_) { return; }

    this->Create();
    this->GetJsonName();
    // "white.png" �Ƃ���1x1�̔��摜�t�@�C�������\�[�X�Ƃ��ėp�ӂ��Ă�������
    uint32_t handle = texManager_->LoadPngTex("TitleUI/Block");
    handle_ = handle;


    this->scale_={ 1280.0f, 720.0f, 1.0f };

    this->LeftTop_ = { 0.f,0.f };
    this->LeftBottom_ = { 0.0f,720.f };
    this->RightTop_ = { 1280.0f,0.0f };
    this->RightBottom_ = { 1280.0f,720.f };

    this->sprite_->ColorData().color_ = { 0.0f, 0.0f, 0.0f, 0.0f };


    currentState_ = State::Idle;
    isActive_ = false;
}

void BlackScreenTransition::StartFadeOut(float duration, std::function<void()> on_finished) {
    if (isActive_) return;
    currentState_ = State::FadeOut;
    duration_ = duration > 0 ? duration : 0.01f;
    timer_ = 0.0f;
    isActive_ = true;
    onFinishedCallback_ = on_finished;
}

void BlackScreenTransition::StartFadeIn(float duration, std::function<void()> on_finished) {
    if (isActive_) return;
    currentState_ = State::FadeIn;
    duration_ = duration > 0 ? duration : 0.01f;
    timer_ = 0.0f;
    isActive_ = true;
    onFinishedCallback_ = on_finished; // �������̏�����ۑ�����
    this->sprite_->ColorData().color_={ 0.0f, 0.0f, 0.0f, 1.0f };
}

void BlackScreenTransition::Update() {
    if (!isActive_) return;

    const float DELTA_TIME_60FPS = 1.0f / 60.0f;
    timer_ += DELTA_TIME_60FPS;

    float alpha = (currentState_ == State::FadeIn) ? 1.0f - (timer_ / duration_) : timer_ / duration_;
    alpha = std::max(0.0f, std::min(1.0f, alpha));
    this->sprite_->ColorData().color_ = { 0.0f, 0.0f, 0.0f, alpha };

    if (timer_ >= duration_) {
        isActive_ = false;
        currentState_ = State::Idle;
        if (onFinishedCallback_) {
            onFinishedCallback_();
        }
    }
    sprite_->Update();
    WorldMatUpdate();
}

void BlackScreenTransition::Draw2D() {
    if (sprite_ && this->sprite_->ColorData().color_.w > 0.0f) {
        this->Draw();
    }
}