#pragma once
#include "WillLiveStrategy.h"

class PopulatedStrategy : public WillLiveStrategy {
public:
	bool WillLive(int neighbours);
};