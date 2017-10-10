#include "Elf.h"
#include "Orc.h"
#include "Farmer.h"
#include "Shaman.h"
#include "Soldier.h"

#include <vector>
#include <iostream>
using namespace std;

void renderCharacters(vector<Character*> characters) {
	cout << "Rendering game characters: " << endl;
	for(auto& c : characters) {
		c->render();
		cout << endl;
	}
}

int main() {
	vector<Character*> characters;

	Elf* elf = new Elf("Fitanir");
	Orc* orc = new Orc("Brashnog");

	Farmer* farmerElf = new Farmer(new Elf("Mitadíl"));
	Soldier* soldierOrc = new Soldier(new Orc("Orcash"));
	Shaman shamanOrc = Shaman(new Orc("Orciman"));

	characters.push_back(elf);
	characters.push_back(orc);
	characters.push_back(farmerElf);
	characters.push_back(soldierOrc);
	characters.push_back(&shamanOrc);

	renderCharacters(characters);

	cin.get();
}