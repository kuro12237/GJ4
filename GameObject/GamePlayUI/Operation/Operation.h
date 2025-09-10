#pragma once
#include "CLEYERA.h"


class Operation :public SpriteComponent
{
public:
	Operation() = default;
	~Operation() = default;

	void Init() override;

	void Update() override;
private:

};

