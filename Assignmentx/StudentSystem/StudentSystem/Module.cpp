#include "Module.h"

Module::Module(int ec, string n, Teacher t) {
	assignedECs = ec;
	name = n;
	teacher = &t;
}

string Module::getName() {
	return name;
}

string Module::getTeacherName() {
	return teacher->getName();
}

void Module::assignECs(int ec) {
	assignedECs = ec;
}