#pragma once
#include <iostream>
#include <string>

using namespace std;

class Character {
public:
	virtual void render();
protected:
	string name;
};