#include "GameOfLife.h"
#include <ctime>

GameOfLife::GameOfLife(int _lifeCycle, int _lifeCycleCount) {
	lifeCycleDuration = _lifeCycle;
	lifeCycleCount = _lifeCycleCount;
	currentLifeCycle = 0;
}

void GameOfLife::run() {
	long int currentTime = static_cast<long int>(time(NULL));
	if (currentLifeCycle == 0 || ((currentTime - startCycleTime) >= lifeCycleDuration)) {
		startNewCycle(currentTime);
	}
	else {
		startedNewCycle = false;	
	}
}

bool GameOfLife::isRunning() {
	if (currentLifeCycle >= lifeCycleCount) {
		return false;
	}
	else { 
		return true;
	}
}

void GameOfLife::startNewCycle(long int _currentTime) {
	if (currentLifeCycle < lifeCycleCount) {
		startedNewCycle = true;
		currentLifeCycle++;
		startCycleTime = _currentTime;
	}
}

int GameOfLife::getCurrentLifeCycle() {
	return currentLifeCycle;
}