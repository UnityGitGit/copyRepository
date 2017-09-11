#pragma once
#include <iostream>
#include <list>
using namespace std;

#ifndef SCHEDULE_H
#define SCHEDULE_H

class Schedule {
private:
	list<Lesson> defineLessons();
	list<DaySchedule> allDaySchedules;
	int currentWeekNumber;
	void drawSchedule();
	FieldOfStudy userFieldOfStudy;

public:
	Schedule(int cWeekNumber);
	void nextWeekSchedule(), prevWeekSchedule();
};

#endif