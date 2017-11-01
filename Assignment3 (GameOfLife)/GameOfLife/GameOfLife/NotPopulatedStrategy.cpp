#include "NotPopulatedStrategy.h"

bool NotPopulatedStrategy::WillLive(int neighbours) {
	if (neighbours == 3){
		return true;
	}
	else {
		return false;
	}
}