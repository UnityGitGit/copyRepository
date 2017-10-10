#include "Shaman.h"

Shaman::Shaman(Character* _character) : Decorator(_character) {}

void Shaman::render() {
	Decorator::render();
	cout << " (shaman)";
}
