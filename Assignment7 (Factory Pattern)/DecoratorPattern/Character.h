#pragma once
#include <iostream>
#include <string>

using namespace std;

class Character {
public:
	static Character* makeCharacter(int race, int role, string name);
	virtual void render();
protected:
	string name;
};