#include "NodeLifeHandler.h"

NodeLifeHandler::NodeLifeHandler() {}

void NodeLifeHandler::setStrategy(WillLiveStrategy *_newStrategy) {
	strategy = _newStrategy;
}

bool NodeLifeHandler::canBePopulated(int neighbourCount) {
	return strategy->WillLive(neighbourCount);
}