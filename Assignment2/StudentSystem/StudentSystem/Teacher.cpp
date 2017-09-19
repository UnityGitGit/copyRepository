#include "Teacher.h"

Teacher::Teacher() {
	name = "default";
}

Teacher::Teacher(string n) {
	name = n;
}

string Teacher::getName() {
	return name;
}