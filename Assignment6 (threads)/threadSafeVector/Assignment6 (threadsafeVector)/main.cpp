#pragma once
#include <iostream>
#include <vector>
#include <thread>
#include <string>
#include <random>
#include "concurrent_vector.h"
#include "concurrent_vector.cpp"

int indx = 0;
concurrent_vector<int> myValues;

void addManyValuesToVector(int amount) {
	for (int i = 0; i < amount; i++) {
		myValues.add(i);
	}
}

void checkConcurrentVectorResults();

int main() {
	checkConcurrentVectorResults();

	std::cin.get();
	return 0;
}

void checkConcurrentVectorResults() {
	//create threads:
	std::thread addvalues1(addManyValuesToVector, 3000);
	std::thread addvalues2(addManyValuesToVector, 3000);

	addvalues1.join();
	addvalues2.join();

	//debut output value(the right result would be 60000): 
	std::cout << "vector size: " << myValues.size();
}