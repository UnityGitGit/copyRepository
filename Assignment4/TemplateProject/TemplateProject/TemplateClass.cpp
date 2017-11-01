#include "TemplateClass.h"

template<class A_Type>
void TemplateClass<A_Type>::put(A_Type newElement) {
	allElements.push_back(newElement);
}

template<class A_Type>
A_Type TemplateClass<A_Type>::pop() {
	A_Type = allElements.at(0);
	return A_Type;
}

template<class A_Type>
int TemplateClass<A_Type>::size() {
	return allElements.size();
}