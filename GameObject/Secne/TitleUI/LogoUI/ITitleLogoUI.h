#pragma once
#include "CLEYERA.h"

class ITitleLogo : public SpriteComponent
{
public:
	ITitleLogo() {};
	virtual ~ITitleLogo() {};

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
