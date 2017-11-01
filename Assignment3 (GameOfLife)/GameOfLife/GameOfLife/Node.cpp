#include "Node.h"
 
Node::Node(int _xPos, int _yPos, NotPopulatedStrategy *_unpopulatedStrategy, PopulatedStrategy *_populatedStrategy) {
	xPos = _xPos;
	yPos = _yPos;
	populated = false;
	willBePopulated = false;

	unpopulatedStrategy = _unpopulatedStrategy;
	populatedStrategy = _populatedStrategy;
	lifeHandler = NodeLifeHandler();
}

void Node::assignNeighbours(vector<Node*> _neighbours) {
	neighbours = _neighbours;
}

void Node::populateAtStart() {//wordt aangeroepen in het begin
	populated = true;
	//grid->nodePopulated();
}

bool Node::isPopulated() {
	return populated;
}

void Node::nextLifeCycle() {
	int populatedNeighbours = getPopulatedNeighbourCount();
	if (populated) {
		lifeHandler.setStrategy(populatedStrategy);
	}
	else {
		lifeHandler.setStrategy(unpopulatedStrategy);
	}
	willBePopulated = lifeHandler.canBePopulated(populatedNeighbours);
}

int Node::getPopulatedNeighbourCount() {
	int count = 0;
	vector<Node*>::iterator it = neighbours.begin();
	while (it != neighbours.end()) {
		if ((*it)->isPopulated()) {
			count++;
		}
		it++;
	}

	return count;
}

void Node::setPopulated() {
	populated = willBePopulated;
}