#pragma once
#include <iostream>
#include <string>

using namespace std;

class Teacher {
public:
	Teacher();
	Teacher(string n);
	string getName();
private:
	string name;
};