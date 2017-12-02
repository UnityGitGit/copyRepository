#pragma once

#define MOVESEMANTICS

#include <string>
#include <ostream>

#ifdef _MSC_VER

#else
#define _NOEXEPT noexcept
#endif

using namespace std;

class Block {
public:
	Block();

	// copy-constructor
	Block(const Block& other);

	virtual ~Block() noexcept;
	// normal (copy) assignment-operator
	Block& operator=(const Block& other);

	Block operator+(const Block& other) const;

#ifdef MOVESEMANTICS
	// move-constructor
	Block(Block&& other) noexcept;
	// move-assignment operator
	Block& operator=(Block&& other) noexcept;
#endif
	void setup(int value);

private:
	string data;
	int value;

	friend ostream& operator<<(ostream& os, const Block& block);
};

