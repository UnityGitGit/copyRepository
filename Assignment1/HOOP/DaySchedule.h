#pragma once
#include <iostream>
#include <list>
#include "Lesson.h"

#ifndef DAYSCHEDULE_H
#define DAYSCHEDULE_H

using namespace std;

class DaySchedule {
public:
	DaySchedule(int dayNmbr, list<Lesson> allSubjects, FieldOfStudy fieldOfStudy);
	int dayNumber;//day number of the college year
	list<Lesson> subjectsOfThisDay;
	void drawThisDaySchedule();
};

#endif