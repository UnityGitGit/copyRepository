#include "NodeHolder.h"
#include "GameOfLife.h"

int main() {
	//gridscript works with [y,x] coordinates and nodes work with [x,y] coordinates
	//[y,x] is more usefull for drawing the grid since we can only draw row after row
	NodeHolder gridScript = NodeHolder();
	gridScript.createGrid(25,25);

	gridScript.populate(15);//populates random with a fillPercentage of 10
	//gridScript.populateNode(12, 12);
	//gridScript.populateNode(13, 13);
	//gridScript.populateNode(14, 11);
	//gridScript.populateNode(14, 12);
	//gridScript.populateNode(14, 13);

	gridScript.drawGrid();
	
	cout << "Starting grid:" << endl;

	GameOfLife gameScript = GameOfLife(2, 20);//(life cycle duration, life cycle count)
	cout << "----------Current life cycle: " << gameScript.getCurrentLifeCycle();
	cout << "; populated node count: " << gridScript.getPopulatedNodeCount() << "----------" << endl;

	while (gameScript.isRunning()) {
		gameScript.run();
		if (gameScript.startedNewCycle) {
			gridScript.lifeRepopulate();
			gridScript.drawGrid();
			cout << "----------Current life cycle: " << gameScript.getCurrentLifeCycle();
			cout << "; populated node count: " << gridScript.getPopulatedNodeCount() << "----------" << endl;
		}
	}

	cout << endl << "The End" << endl;

	//pause the 'game'
	cin.get();

	return 0;
}