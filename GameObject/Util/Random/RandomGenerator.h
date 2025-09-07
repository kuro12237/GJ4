#pragma once
#include"CLEYERA/CLEYERA.h"

class RandomGenerator
{
public:

	static RandomGenerator* GetInstance();

	static float GetFloat(const float& min, const float& max);

	static int GetInt(const int& min, const int& max);

	template<typename T>
	static T GetParam(const T& min, const T& max) { return GetFloat(min, max); }

	template<>
	static Math::Vector::Vec3 GetParam<Math::Vector::Vec3>(const Math::Vector::Vec3& min, const Math::Vector::Vec3& max) {
		return{
			GetParam<float>(min.x,max.x),
			GetParam<float>(min.y,max.y),
			GetParam<float>(min.z,max.z)
		};
	}

	template<>
	static Math::Vector::Vec4 GetParam<Math::Vector::Vec4>(const Math::Vector::Vec4& min, const Math::Vector::Vec4& max) {
		return{
			GetParam<float>(min.x,max.x),
			GetParam<float>(min.y,max.y),
			GetParam<float>(min.z,max.z),
			GetParam<float>(min.w,max.w)
		};
	}
private:

	std::random_device device_ ;

};
