#pragma once
#include "TemplateClass.h"
#include <vector>
#include <string>

template<typename A_Type>
vector<A_Type> sortedVectorArr(vector<A_Type> arr) {
	int arrSize = arr.size();
	if (arrSize < 2)
		return arr;

	vector<A_Type> newArr;

	for (int i = 0; i < arrSize; i ++) {
		//get index of smallest element
		int smallestIndx = smallestElementIndx(arr);

		//bring smallest element to front of new array and remove it from old array
		A_Type temp = arr.at(smallestIndx);
		arr.erase(arr.begin() + smallestIndx);
		newArr.push_back(temp);
	}

	return newArr;
}

template<typename A_Type>
int smallestElementIndx(vector<A_Type> arr) {
	A_Type smallestValue = arr.at(0);
	int smallestValueIndx = 0;
	int arrSize = arr.size();

	if (arrSize == 1)
		return smallestValueIndx;

	for (int i = 1; i < arrSize; i++) {
		A_Type currentValue = arr.at(i);
		if (currentValue < smallestValue) {
			smallestValue = currentValue;
			smallestValueIndx = i;
		}
	}

	return smallestValueIndx;
}

void debugTemplateFunction();
void debugTemplateClass();

int main()
{
	//gek genoeg werkt het niet helemaal voor strings sorteren... geen idee waarom
	debugTemplateFunction();
	cout << endl;
	debugTemplateClass();

	cin.get();
}

void debugTemplateFunction() {
	vector<float> myFloatValues = { 0.5f, 13.3f, 0.999f, 30.3f, 20, 0.2f };
	//sort values:
	vector<float> sortedValues = sortedVectorArr(myFloatValues);

	//output sorted values:
	for (float f : sortedValues) cout << f << ", ";
	cout << endl;

	vector<string> myUsernames = { "pieter", "i", "king", "player1", "man", "some name" };
	//sort usernames:
	vector<string> sortedUsernames = sortedVectorArr(myUsernames);

	//output sorted usernames:
	for (string s : sortedUsernames) cout << s << ", ";
	cout << endl;
}

void debugTemplateClass() {
	TemplateClass<float> myValues;
	//assign values:
	myValues.put(3.5f);
	myValues.put(0.3f);
	myValues.put(7.7f);
	myValues.put(30.1f);

	//test if it works:
	cout << "Created a float array with " << myValues.size() << " values:" << endl;
	cout << "First value of array: " << myValues.pop() << endl;
}