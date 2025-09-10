#pragma once
#include "CLEYERA.h"
#include "../Secne/TitleUI/SelectUI/ISelectUI.h"

class IGamePlayStandbyUI : public SpriteComponent
{
public:
	IGamePlayStandbyUI() {};
	virtual ~IGamePlayStandbyUI() {};

	virtual void Init() {};

	// �A�j���[�V�����̍X�V����
	virtual void Update() {
		if (!isAnimating_) return;

		const float DELTA_TIME_60FPS = 1.0f / 60.0f;
		animationTimer_ += DELTA_TIME_60FPS;
		float t = animationTimer_ / animationDuration_;

		if (t >= 1.0f) {
			t = 1.0f;
			isAnimating_ = false;
		}

		// �A�j���[�V�����̗�F�g�債�Ȃ���t�F�[�h�A�E�g����
		float currentScale = AnimationUtil::Lerp(startScale_, endScale_, t);
		float currentAlpha = AnimationUtil::Lerp(1.0f, 0.0f, t);

		this->scale_ = { currentScale, currentScale, 1.0f };
		this->SetAlpha(currentAlpha);
	}

	// �A�j���[�V�������J�n������
	void StartAnimation(float startScale, float endScale, float duration) {
		startScale_ = startScale;
		endScale_ = endScale;
		animationDuration_ = duration;
		animationTimer_ = 0.0f;
		isAnimating_ = true;
		SetVisible(true); // �A�j���[�V�����J�n���ɕK���\������
		this->scale_ = { startScale_, startScale_, 1.0f };

	}

	// ���ߓx��ݒ肷��
	virtual void SetAlpha(float alpha) {
		if (sprite_) {
			this->sprite_->ColorData().color_ = { 1.0f, 1.0f, 1.0f, alpha };
		}
	}

	// �\��/��\����؂�ւ���
	void SetVisible(bool visible) {
		isVisible_ = visible;
		// �A�j���[�V�������łȂ���΁A�\����Ԃɉ����ē����x�𑦎��ύX
		if (!isAnimating_) {
			SetAlpha(visible ? 1.0f : 0.0f);
		}
	}

	bool IsVisible() const { return isVisible_; }

protected:
	bool isAnimating_ = false;
	float animationTimer_ = 0.0f;
	float animationDuration_ = 1.0f;
	float startScale_ = 0.8f;
	float endScale_ = 1.2f;
	bool isVisible_ = false;
};