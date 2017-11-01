#include "Student.h"

Student::Student(string n) {
	name = n;
}

void Student::assignModule(Module m){
	myModules.push_back(&m);
}

int Student::getTotalECs() {
	int ecs = 0;
	vector<Module*>::iterator it = myModules.begin();
	while (it != myModules.end()) {
		ecs += (*it)->getAssignedECs();
		it++;
	}

	return ecs;
}

string Student::getName() {
	return name;
}