#pragma once
#pragma once
#include "CLEYERA.h"


class ISubUI : public SpriteComponent
{
public:
	ISubUI() {};
	virtual ~ISubUI() {};

	virtual void Init() {}

	virtual void Update() {}

	virtual void SetAlpha(float alpha) {
		// sprite_の色情報を変更。R,G,Bは1.0f(白)のまま、Alpha値のみ変更する
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


private:


};
