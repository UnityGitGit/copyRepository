#pragma once
#include "Decorator.h"

class Shaman :public Decorator
{
public:
	Shaman(Character* _character);
	void render() override;
};

