#include "Character.h"
#include "Elf.h"
#include "Orc.h"
#include "Farmer.h"
#include "Shaman.h"
#include "Soldier.h"


Character* Character::makeCharacter(int race, int role, string name){
	Character* c = new Elf("ERROR TRIGGERED");

	switch (race) {
	case 1:
		c = new Elf(name);
		break;
	case 2:
		c = new Orc(name);
	}

	switch (role) {
	case 1:
		c = new Farmer(c);
		break;
	case 2:
		c = new Shaman(c);
		break;
	case 3:
		c = new Soldier(c);
		break;
	}

	return c;
}

void Character::render() {
	cout << name;
}