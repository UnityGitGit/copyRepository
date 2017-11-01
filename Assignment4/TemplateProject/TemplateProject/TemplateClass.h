#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<typename A_Type>
class TemplateClass {
public:
	void put(A_Type newElement) {
		allElements.push_back(newElement);
	}
	A_Type pop() {
		A_Type firstElement = allElements.at(0);
		return firstElement;
	}
	int size() {
		return allElements.size();
	}
private:
	vector<A_Type> allElements;
};