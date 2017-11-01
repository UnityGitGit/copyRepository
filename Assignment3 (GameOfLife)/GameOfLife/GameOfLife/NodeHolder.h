#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Node.h"

using namespace std;

class NodeHolder {
public:
	NodeHolder();
	void createGrid(int _xSize, int _ySize);
	void drawGrid();

	void populate(int populationPercentage);
	void populateNode(int y, int x);

	int getPopulatedNodeCount();
	void lifeRepopulate();
private:
	vector<vector<Node>> nodes;
	void assignNodeNeighbours(int nodeY, int nodeX);
	int gridXSize;
	int gridYSize;

	int populatedNodes;
};