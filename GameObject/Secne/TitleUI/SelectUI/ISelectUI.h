#pragma once
#include "CLEYERA/CLEYERA.h"


// �C�[�W���O�֐��Ȃǂ��܂Ƃ߂��V���v���ȃw���p�[
namespace AnimationUtil {
	inline float Lerp(float start, float end, float t) {
		return start + t * (end - start);
	}
}

class ISelectUI : public SpriteComponent
{
public:
	ISelectUI() {};
	virtual ~ISelectUI() {};

	virtual void Init() {};

	virtual void Update() {
		if (!isAnimating_) { return; }

		const float DELTA_TIME_60FPS = 1.0f / 60.0f; // 60FPS����1�t���[���̎���
		animationTimer_ += DELTA_TIME_60FPS;

		float t = animationTimer_ / animationDuration_;

		// t��1�𒴂��Ȃ��悤�ɃN�����v
		if (t > 1.0f) {
			t = 1.0f;
			isAnimating_ = false;
		}

		// Lerp�i���`��ԁj���g���Č��݈ʒu���v�Z
		currentPos_.x = AnimationUtil::Lerp(startPos_.x, targetPos_.x, t);
		currentPos_.y = AnimationUtil::Lerp(startPos_.y, targetPos_.y, t);

		this->SetTranslate(currentPos_);
	}

	// �A�j���[�V�������J�n������֐�
	void StartSlideAnimation(const Math::Vector::Vec2& start, const Math::Vector::Vec2& end, float duration = 0.3f) {
		startPos_ = start;
		targetPos_ = end;
		animationDuration_ = duration;
		animationTimer_ = 0.0f;
		isAnimating_ = true;
	}

	bool IsAnimating() const { return isAnimating_; }

	virtual void SetAlpha(float alpha) {
		// sprite_�̐F����ύX�BR,G,B��1.0f(��)�̂܂܁AAlpha�l�̂ݕύX����
		if (sprite_) {
			this->sprite_->ColorData().color_ = { 1.0f, 1.0f, 1.0f, alpha };
		}
	}

#pragma region Set

	virtual void SetScale(const Math::Vector::Vec2& scale) {
		this->scale_ = {
			scale.x, scale.y, 0.0f
		};
	}

	virtual void SetTranslate(const Math::Vector::Vec2& pos) {
		this->translate_ = {
			pos.x, pos.y, 0.0f
		};
	}


#pragma endregion


protected:
	// �A�j���[�V�����֘A�̕ϐ�
	bool isAnimating_ = false;
	float animationTimer_ = 0.0f;
	float animationDuration_ = 0.3f; // 0.3�b�ŃX���C�h

	Math::Vector::Vec2 startPos_{};
	Math::Vector::Vec2 targetPos_{};
	Math::Vector::Vec2 currentPos_{};

};
