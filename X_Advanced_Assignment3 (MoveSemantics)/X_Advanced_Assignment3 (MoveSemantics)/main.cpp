#include <iostream>
#include "Block.h"
#include "Parent.h"

// dummy function that operates on the Block
Block fillBlock(Block b, int value) {
    std::cout << " parameter b " << &b << std::endl;

    b.setup(value);
    return b;
}

void moveAssignmentOperator() {
	std::cout << "Start move-assignment-testing on Block:" << std::endl;

	Block block;
	std::cout << " Block: " << block << std::endl;

	std::cout << "Assignment" << std::endl;
	Block otherblock = fillBlock(block, 10);

	std::cout << "Na Assignment" << std::endl;
	std::cout << " StartBlock:" << block << std::endl;
	std::cout << " OtherBlock:" << otherblock << std::endl;

	std::cout << "End" << std::endl << std::endl;
}

//returns a moved version of p
Parent otherParent(Parent& p) {
	Parent newParent = Parent(p);
	return newParent;
}

void moveConstructor() {
	Parent startParent = Parent("Peter");
	std::cout << "start parent name: " << startParent.childName() << std::endl;
	Parent nextParent = otherParent(startParent);
	std::cout << "start parent name: " << startParent.childName() << std::endl;
	std::cout << "next parent name: " << nextParent.childName() << std::endl;
}
 
int main() {
	//assignment1:
	moveAssignmentOperator();
	std::cout << std::endl << std::endl;

	//assignment2:
	moveConstructor();
	//wat ik me hierbij wel afvraag is waarom startParentName hetzelfde blijft na de move_constructor

	std::cin.get();
    return 0;
}