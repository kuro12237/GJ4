#pragma once
#include "CLEYERA.h"

class ISelectUI : public SpriteComponent
{
public:
	ISelectUI() {};
	virtual ~ISelectUI() {};

	virtual void Init() {}

	virtual void Update() {}

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
