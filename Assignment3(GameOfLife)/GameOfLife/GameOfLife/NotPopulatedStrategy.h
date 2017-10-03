#pragma once
#include "WillLiveStrategy.h"

class NotPopulatedStrategy : public WillLiveStrategy {
public:
	bool WillLive(int neighbours);
};