#include "Dinosaur.h"
#include <string>

Dinosaur::Dinosaur(string _name) {
	name = _name;
}

string Dinosaur::getName() {
	return name;
}