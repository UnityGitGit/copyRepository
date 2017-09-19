#pragma once
#include <iostream>
#include <list>
 
#ifndef LESSON_H
#define LESSON_H

using namespace std;

class Lesson {
private:
	int width, height;

public:
	Lesson(int w, int h, string _name, string _local, list<FieldOfStudy> _fieldsOfStudy, float _sTime, float _eTime, int _dOfYear);
	string name, local;
	list<string> teachers;//->alle leraren die dit vak geven, meestal is het er maar 1; 
	list<FieldOfStudy> fieldsOfStudy;//de studierichting(en) waarvoor dit vak bedoeld is

	//variabelen die gebruikt wordt om de vakken te ordenen:
	float startTime, endTime;
	int dayOfYear;

	void draw();
	void enlarge(float enlargeFactor), minimize(float minimizeFactor);
};

#endif

enum FieldOfStudy {gameDev, gameArt, gameDesign, etc};