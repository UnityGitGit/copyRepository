#include "Park.h"

#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

Park::Park() {}
void Park::addDinosaur(Dinosaur d) {
	dinosaurs.push_back(d);
}

void Park::list() {
	std::cout << "----- In the park:" << std::endl;
	std::vector<Dinosaur>::iterator it = dinosaurs.begin();
	while (it != dinosaurs.end()) {
		std::cout << it->getName() << std::endl;
		it++;
	}
	std::cout << "-----" << std::endl;
}

void Park::openGate() {
	cout << "Oh no! The gate has been left open!" << endl;
	std::vector<Dinosaur>::iterator it = dinosaurs.begin();
	while (it != dinosaurs.end()) {
		if (it->getName() == "Velociraptor") {
			std::cout << "Escaped: " << it->getName() << std::endl;
			it = dinosaurs.erase(it);

			int deadDinoIndx = rand() % 2;
			std::cout << it->getName() << " ate the " << dinosaurs.at(deadDinoIndx).getName() << "!!!" << endl;
			it = dinosaurs.erase(dinosaurs.begin() + deadDinoIndx);
		}
		else {
			cout << it->getName() << " is still in the park" << endl;
			it++;
		}
	}
}