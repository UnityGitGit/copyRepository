#pragma once
#include <vector>
#include <mutex>
using namespace std;

template <class T>
class concurrent_vector {
public:
	void add(T newElement);
	T at(int index);
	int size();

private:
	std::mutex myMutex;
	vector<T> allElements;
};