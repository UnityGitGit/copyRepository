#include "PopulatedStrategy.h"

bool PopulatedStrategy::WillLive(int neighbours) {
	if (neighbours >= 2 && neighbours <= 3) {
		return true;
	}
	else {
		return false;
	}
}