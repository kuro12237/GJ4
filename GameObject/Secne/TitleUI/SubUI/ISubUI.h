#pragma once
#include "CLEYERA/CLEYERA.h"


class ISubUI : public SpriteComponent
{
public:
	ISubUI() {};
	virtual ~ISubUI() {};

	virtual void Init() {}

	virtual void Update() {}

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


private:


};
