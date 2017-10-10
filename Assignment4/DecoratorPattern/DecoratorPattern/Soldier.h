#pragma once
#include "Decorator.h"

class Soldier : public Decorator
{
public:
	Soldier(Character* _character);
	void render() override;
};

