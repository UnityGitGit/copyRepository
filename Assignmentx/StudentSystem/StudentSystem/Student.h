#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Module.h"

using namespace std;

class Student {
public:
	Student(string n);
	void assignModule(Module m);
	int getTotalECs();
	string getName();

private:
	string name;
	vector<Module*> myModules;
};