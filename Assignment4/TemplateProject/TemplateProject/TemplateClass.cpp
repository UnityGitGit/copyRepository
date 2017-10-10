#include "TemplateClass.h"

template<class T>
void TemplateClass<T>::put(T newElement) {
	allElements.push_back(newElement);
}

template<class T>
T TemplateClass<T>::pop() {
	T = allElements.at(0);
	return T;
}

template<class T>
int TemplateClass<T>::size() {
	return allElements.size();
}