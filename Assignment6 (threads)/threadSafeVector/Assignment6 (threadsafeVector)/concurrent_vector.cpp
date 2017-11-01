#include "concurrent_vector.h"

template <class T>
void concurrent_vector<T>::add(T newElement) {
	//make operation thread-safe:
	std::lock_guard<std::mutex> lock(myMutex);

	allElements.push_back(newElement);
}

template <class T>
T concurrent_vector<T>::at(int index) {
	T valueAtIndex = allElements.at(index);
	return valueAtIndex;
}

template <class T>
int concurrent_vector<T>::size() {
	int elementsSize = (int)allElements.size();
	return elementsSize;
}