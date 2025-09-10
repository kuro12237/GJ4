#pragma once
#include "CLEYERA.h"

/// <summary>
/// ƒJƒƒ‰
/// </summary>
class CameraUI : public CLEYERA::Component::CameraCompornent {
public:
	CameraUI() {};
	~CameraUI() {};

	void Init() override;

	void Update() override;

#pragma region Get

	Math::Vector::Vec3& GetTranslate() { return translate_; }

#pragma endregion


private:

	Math::Vector::Vec3 offset_ = {};
	float speed_ = 0.0f;
};
