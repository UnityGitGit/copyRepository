#include "Schedule.h"
#include "Lesson.h"
#include "DaySchedule.h"

Schedule::Schedule(int cWeekNumber) {
	currentWeekNumber = cWeekNumber;
	list<Lesson> allClassesGivenThisYear = defineLessons(); //belachelijk maar waar
	//vul alle daySchedules in mbv 'allclassesgiventhisyear' and 'userFieldOfStudy'

	drawSchedule();
}
 
list<Lesson> Schedule::defineLessons() {
	//get all Lessons from a db
	//return as a list
}

void Schedule::drawSchedule() {
	//gebruik het currentWeekNumber om alle bijbehorende daySchedules weer te geven
}

void Schedule::nextWeekSchedule() {
	currentWeekNumber++;
	drawSchedule();
}
void Schedule::prevWeekSchedule() {
	currentWeekNumber--;
	drawSchedule();
}

int main() {
	return 0;
}