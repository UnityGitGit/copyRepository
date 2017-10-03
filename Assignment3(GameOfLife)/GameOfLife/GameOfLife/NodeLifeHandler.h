#pragma once
#include "WillLiveStrategy.h"

class NodeLifeHandler {
public:
	NodeLifeHandler();
	void setStrategy(WillLiveStrategy *_newStrategy);
	bool canBePopulated(int neighbourCount);
private:
	WillLiveStrategy* strategy;
};
