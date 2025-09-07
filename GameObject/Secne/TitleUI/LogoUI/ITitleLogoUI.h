#pragma once
#include "CLEYERA/CLEYERA.h"
#include "../SelectUI/ISelectUI.h"

class ITitleLogo : public SpriteComponent
{
public:
	ITitleLogo() {};
	virtual ~ITitleLogo() {};

	virtual void Init() {}

	virtual void Update() {
		if (!isAnimating_) { return; }

		const float DELTA_TIME_60FPS = 1.0f / 60.0f;
		animationTimer_ += DELTA_TIME_60FPS;
		float t = animationTimer_ / animationDuration_;

		if (t > 1.0f) {
			t = 1.0f;
			isAnimating_ = false;
		}

		currentPos_.x = AnimationUtil::Lerp(startPos_.x, targetPos_.x, t);
		currentPos_.y = AnimationUtil::Lerp(startPos_.y, targetPos_.y, t);

		this->SetTranslate(currentPos_);
		
	}

	void StartAnimation(const Math::Vector::Vec2& start, const Math::Vector::Vec2& end, float duration = 0.5f) {
		startPos_ = start;
		targetPos_ = end;
		animationDuration_ = duration;
		animationTimer_ = 0.0f;
		isAnimating_ = true;
		this->SetTranslate(start); // 開始位置をセット
	}

	bool IsAnimating() const { return isAnimating_; }

	virtual void SetAlpha(float alpha) {
		// sprite_の色情報を変更。R,G,Bは1.0f(白)のまま、Alpha値のみ変更する
		if (sprite_) {
			this->sprite_->ColorData().color_={ 1.0f, 1.0f, 1.0f, alpha };
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
	// ★★★★★ アニメーション用変数を追加 ★★★★★
	bool isAnimating_ = false;
	float animationTimer_ = 0.0f;
	float animationDuration_ = 0.5f;

	Math::Vector::Vec2 startPos_{};
	Math::Vector::Vec2 targetPos_{};
	Math::Vector::Vec2 currentPos_{};

};
