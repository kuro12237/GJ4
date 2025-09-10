#pragma once
#include "CLEYERA.h"
#include <functional>

class BlackScreenTransition : public SpriteComponent {
public:
    static BlackScreenTransition* GetInstance();

    void Init()override;
    void Update()override;
    void Draw2D();

    void Finalize();

    void StartFadeOut(float duration, std::function<void()> on_finished = nullptr);
    void StartFadeIn(float duration, std::function<void()> on_finished = nullptr);
    bool IsActive() const { return isActive_; }

    bool isOverReturn(){ 
        bool result = isChangeReturn_;
        isChangeReturn_ = false;
        return result; }
private:
    BlackScreenTransition() = default;
    ~BlackScreenTransition();
    BlackScreenTransition(const BlackScreenTransition&) = delete;
    BlackScreenTransition& operator=(const BlackScreenTransition&) = delete;

    enum class State { Idle, FadeIn, FadeOut };
    State currentState_ = State::Idle;
    bool isActive_ = false;
    float timer_ = 0.0f;
    float duration_ = 1.0f;
    std::function<void()> onFinishedCallback_;

    bool isChangeReturn_ = false;

};