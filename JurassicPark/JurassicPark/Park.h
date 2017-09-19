#pragma once

#include <vector>

#include "Dinosaur.h"
//edwin
class Park {
public:
	Park();

	void addDinosaur(Dinosaur d);

	void list();

	void openGate();

private:
	std::vector<Dinosaur> dinosaurs;

};

