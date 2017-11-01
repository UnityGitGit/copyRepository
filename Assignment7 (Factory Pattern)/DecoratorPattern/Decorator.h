#pragma once
#include "Character.h"

class Decorator : public Character {
public:
	Decorator(Character* _character);
	void render() override;

private:
	Character* character;
};
