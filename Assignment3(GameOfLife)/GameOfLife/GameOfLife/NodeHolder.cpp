#include "NodeHolder.h"
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "NotPopulatedStrategy.h"
#include "PopulatedStrategy.h"

NodeHolder::NodeHolder() {
	populatedNodes = 0;
	srand(static_cast<long int>(time(NULL)));
}

void NodeHolder::createGrid(int _xSize, int _ySize) {
	gridYSize = _ySize;
	gridXSize = _xSize;

	NotPopulatedStrategy* notPopulatedStrategy = new NotPopulatedStrategy();
	PopulatedStrategy* populatedStrategy = new PopulatedStrategy();

	for (int y = 0; y < gridYSize; y++) {
		vector<Node> xNodeVector;

		for (int x = 0; x < gridXSize; x++) {
			xNodeVector.push_back(Node(x, y, notPopulatedStrategy, populatedStrategy));
		}

		nodes.push_back(xNodeVector);
	}

	for (int y = 0; y < gridYSize; y++) {
		for (int x = 0; x < gridXSize; x++) {
			assignNodeNeighbours(y,x);
		}
	}
}

void NodeHolder::assignNodeNeighbours(int nodeY, int nodeX) {
	vector<Node*> neighbours;

	int minY = max(nodeY - 1, 0);
	int maxY = min(nodeY + 1, gridYSize - 1);
	int minX = max(nodeX - 1, 0);
	int maxX = min(nodeX + 1, gridXSize - 1);

	for (int y = minY; y <= maxY; y++) {
		for (int x = minX; x <= maxX; x++) {
			if (y == nodeY && x == nodeX) {
				continue;
			}

			neighbours.push_back(&nodes[y][x]);
		}
	}

	nodes[nodeY][nodeX].assignNeighbours(neighbours);
}

void NodeHolder::drawGrid() {
	for (int y = 0; y < gridYSize; y ++) {
		string currentRow = "";
		vector<Node> yNodeVector = nodes.at(y);

		for (int x = 0; x < gridXSize; x ++) {
			string nodeFill = " X";
			if (yNodeVector.at(x).isPopulated()) {
				nodeFill = " -";
			}
			currentRow += nodeFill;
		}

		cout << currentRow << endl;
	}
}

void NodeHolder::populate(int populationPercentage) {
	for (int y = 0; y < gridYSize; y++) {
		for (int x = 0; x < gridXSize; x++) {
			int randValue = rand() % 100;
			if (randValue < populationPercentage) {
				populateNode(y,x);
			}
		}
	}
}

void NodeHolder::populateNode(int y, int x) {
	nodes[y][x].populateAtStart();
	populatedNodes++;
}

int NodeHolder::getPopulatedNodeCount() {
	return populatedNodes;
}

void NodeHolder::lifeRepopulate() {//aangeroepen in elke life cycle
	for (int y = 0; y < gridYSize; y ++) {
		for (int x = 0; x < gridYSize; x++) {
			nodes[y][x].nextLifeCycle();
		}
	}

	populatedNodes = 0;
	for (int y = 0; y < gridYSize; y++) {
		for (int x = 0; x < gridYSize; x++) {
			Node* current = &nodes[y][x];
			current->setPopulated();
			if (current->isPopulated()) {
				populatedNodes++;
			}
		}
	}
}