#pragma once
#include "Decorator.h"

class Farmer :public Decorator{
	public:
		Farmer(Character* _character);
		void render() override;
};

