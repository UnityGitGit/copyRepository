#include <iostream>
#include "Parent.h"

Parent::Parent(string name) {
	this->name = name;
	string childName = "ChildOf" + name;
	this->child = new Child(childName);
}

Parent::Parent(const Parent& other) {
	cout << "Parent cctor" << endl;
	this->name = other.name;
	this->child = new Child(*other.child);
}

Parent::Parent(Parent&& other) {
	std::cout << "move constructor is being called" << std::endl;

	this->name = other.name;
	this->child = other.child;

	other.name = "nonName";
	other.child = nullptr;
}

Parent::~Parent() {
	delete this->child;
}

Parent& Parent::operator=(const Parent& other) {
	cout << "Parent assignment" << endl;

	if (this == &other) {
		return *this;
	}

	this->name = other.name;
	delete this->child;
	this->child = new Child(*other.child);

	return *this;
}

std::string Parent::childName(){
	return child->name;
}

ostream& operator<<(ostream& os, const Parent& parent) {
	if (parent.child == NULL) {
		os << "name: " << parent.name << " child: NULL";
	}
	else {
		os << "name: " << parent.name << " child: " << *parent.child;
	}
	return os;
}
