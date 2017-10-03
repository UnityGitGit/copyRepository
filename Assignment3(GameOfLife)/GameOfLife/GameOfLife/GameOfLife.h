#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "NodeHolder.h"

using namespace std;

class GameOfLife {
public:
	GameOfLife(int _lifeCycle, int _lifeCycleCount);
	void run();
	
	bool isRunning();
	bool startedNewCycle;

	int getCurrentLifeCycle();
private:
	int lifeCycleDuration;
	long int startCycleTime;

	void startNewCycle(long int _currentTime);
	int lifeCycleCount;
	int currentLifeCycle;
};