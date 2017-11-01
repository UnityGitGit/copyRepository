#include "Elf.h"
#include "Orc.h"
#include "Farmer.h"
#include "Shaman.h"
#include "Soldier.h"

#include <vector>
#include <iostream>

void renderCharacters(std::vector<Character*> characters) {
	std::cout << "Rendering game characters: " << std::endl;
	for(auto& c : characters) {
		c->render();
		std::cout << std::endl;
	}
}

std::vector<Character*> createCharactersSimple() {
	std::vector<Character*> characters;

	Elf* elf = new Elf("Fitanir");
	Orc* orc = new Orc("Brashnog");

	Farmer* farmerElf = new Farmer(new Elf("Mitadíl"));
	Soldier* soldierOrc = new Soldier(new Orc("Orcash"));
	Shaman* shamanOrc = new Shaman(new Orc("Orciman"));

	characters.push_back(elf);
	characters.push_back(orc);
	characters.push_back(farmerElf);
	characters.push_back(soldierOrc);
	characters.push_back(shamanOrc);

	return characters;
}

int main() {
	//vector<Character*> characters = createCharactersSimple();
	//renderCharacters(characters);
	//for (int i = 0; i < characters.size(); i++) {
	//	delete characters[i];
	//}

	std::string name;
	int race;
	int role;

	std::cout << "Type in the name of your character: \n";
	std::cin >> name;

	std::cout << "Choose your character's race: [1 == Elf; 2 == Orc] \n";
	std::cin >> race;
	if (race < 1 || race > 2) return 0;//force quit, since we will not be able to create this character!

	std::cout << "Choose your character's role: [0 == none; 1 == farmer; 2 == shaman; 3 == soldier] \n";
	std::cin >> role;

	Character* myCharacter = Character::makeCharacter(race, role, name);
	cout << "Rendering character: ";
	myCharacter->render();

	delete myCharacter;

	std::cin.get();
	std::cin.get();
	return 0;
}