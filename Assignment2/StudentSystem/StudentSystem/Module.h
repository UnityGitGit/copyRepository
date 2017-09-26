#pragma once
#include <iostream>
#include <string>
#include "Teacher.h"

using namespace std;

class Module {
public:
	Module(int ec, string n, Teacher t);
	string getName();
	string getTeacherName();
	void assignECs(int ec);
	int getAssignedECs();
private:
	int assignedECs;
	string name;
	Teacher* teacher;
};