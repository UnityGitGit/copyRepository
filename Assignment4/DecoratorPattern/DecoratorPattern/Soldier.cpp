#include "Soldier.h"

Soldier::Soldier(Character* _character) : Decorator(_character) {}

void Soldier::render() {
	Decorator::render();
	cout << " (soldier)";
}
