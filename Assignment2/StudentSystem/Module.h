#pragma once
#include <iostream>
#include <string>
#include "Teacher.h"

using namespace std;

class Module {
public:
	Module(int ec, string n, Teacher t);
	int assignedECs;
	string getName();
	string getTeacherName();
private:
	string name;
	Teacher teacher;
};