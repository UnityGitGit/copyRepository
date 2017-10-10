#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class TemplateClass {
public:
	void put(T newElement) {
		allElements.push_back(newElement);
	}
	T pop() {
		T firstElement = allElements.at(0);
		return firstElement;
	}
	int size() {
		return allElements.size();
	}
private:
	vector<T> allElements;
};