#include <iostream>
#include "Park.h"

int main(){
	Park thePark = Park();
	thePark.addDinosaur(Dinosaur("Velociraptor"));
	thePark.addDinosaur(Dinosaur("Tyrex"));
	thePark.addDinosaur(Dinosaur("hypotamus"));
	thePark.addDinosaur(Dinosaur("Acheraptor"));

	thePark.list();

	cin.get();

	thePark.openGate();

	cin.get();

	return 0;
}