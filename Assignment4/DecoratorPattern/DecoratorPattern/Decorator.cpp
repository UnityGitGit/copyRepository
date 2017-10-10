#include "Decorator.h"

Decorator::Decorator(Character* _character): character(_character) {}

void Decorator::render() {
	character->render();
}