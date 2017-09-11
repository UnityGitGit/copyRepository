#include "Lesson.h"

Lesson::Lesson(int w, int h, string _name, string _local, list<FieldOfStudy> _fieldsOfStudy,
				float _sTime, float _eTime, int _dOfYear){
	width = w;
	height = h;
	name = _name;
	local = _local;
	fieldsOfStudy = _fieldsOfStudy;

	startTime = _sTime;
	endTime = _eTime;
	dayOfYear = _dOfYear;
}

void Lesson::draw() { 
	//draw this subject on the screen, based on the width and height. 
	//also print other info like local, name and fields of study
}

void Lesson::enlarge(float enlargeFactor) {
	//the user has clicked on the screen to see more info, enlarge the current width and height with the enlargeFactor
	//also print the info like local etc in a more ordered way
}
void Lesson::minimize(float minimizeFactor) {
	//reverse of enlarge
}