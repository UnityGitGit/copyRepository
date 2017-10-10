#include "Farmer.h"

Farmer::Farmer(Character* _character): Decorator(_character){}

void Farmer::render() {
	Decorator::render();
	cout << " (farmer)";
}