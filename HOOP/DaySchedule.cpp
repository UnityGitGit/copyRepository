#include "DaySchedule.h"
#include "Lesson.h"

DaySchedule::DaySchedule(int dayNmbr, list<Lesson> allSubjects, FieldOfStudy fieldOfStudy) {
	dayNumber = dayNmbr;
	//fill in 'subjectsOfThisDay' (found by comparing all lessons' dayNumbers to dayNmbr and checking the users' fieldOfStudy)
}

void DaySchedule::drawThisDaySchedule() {
	for (int i = 0; i < sizeof(subjectsOfThisDay); i ++) {
		subjectsOfThisDay[i].draw();
	}
}