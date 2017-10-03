#pragma once
#include <iostream>
#include "Node.h"
#include <vector>
#include "NodeLifeHandler.h"
#include "NotPopulatedStrategy.h"
#include "PopulatedStrategy.h"

using namespace std;

class Node {
public:
	Node(int _xPos, int _yPos, NotPopulatedStrategy *_unpopulatedStrategy, PopulatedStrategy *_populatedStrategy);
	void assignNeighbours(vector<Node*> _neighbours);
	void populateAtStart();

	bool isPopulated();

	void nextLifeCycle();
	void setPopulated();
private:
	int xPos;
	int yPos;
	bool populated;
	vector<Node*> neighbours;
	int getPopulatedNeighbourCount();

	bool willBePopulated;
	NodeLifeHandler lifeHandler;
	NotPopulatedStrategy* unpopulatedStrategy;
	PopulatedStrategy* populatedStrategy;
};