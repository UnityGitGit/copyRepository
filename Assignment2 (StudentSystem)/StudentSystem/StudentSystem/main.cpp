#include "main.h"
#include <stdlib.h>
#include "Module.h"
#include "Teacher.h"

int main() {
	//create all data on the heap:
	Teacher* tValentijn = new Teacher("Valentijn Muijrers");
	Teacher* tAron = new Teacher("Aron Oostdijk");
	Teacher* tRaf = new Teacher("Raf Croonen");

	Module* coreArt = new Module(3, "Game Art", *tRaf);
	Module* newTechnologies = new Module(2, "New Technologies", *tValentijn);
	Module* coreDevelopment = new Module(3, "Game Development", *tAron);

	vector<Module*> allModules;
	allModules.push_back(coreArt);
	allModules.push_back(newTechnologies);
	allModules.push_back(coreDevelopment);

	vector<Student*> students;
	students.push_back(new Student("Pieter"));
	students.push_back(new Student("Nathan"));
	students.push_back(new Student("Freek"));
	students.push_back(new Student("Frank"));
	students.push_back(new Student("Fred"));
	students.push_back(new Student("Frederik"));
	students.push_back(new Student("Diederik"));
	students.push_back(new Student("Dirk"));
	students.push_back(new Student("Hans"));
	students.push_back(new Student("Grietje"));

	vector<Student*>::iterator itStudents = students.begin();
	vector<Module*>::iterator itModules = allModules.begin();

	//assign random modules to students:
	while (itStudents != students.end()) {
		if ((rand() % 2) == 0) {
			(*itStudents)->assignModule((*coreArt));
		}
		if ((rand() % 2) == 0) {
			(*itStudents)->assignModule((*newTechnologies));
		}
		if ((rand() % 2) == 0) {
			(*itStudents)->assignModule((*coreDevelopment));
		}
		itStudents++;
	}

	//print modules with their teachers:
	cout << "Modules with teachers: doesnt work :( ---------" << endl;
	while (itModules != allModules.end()) {//werkt niet.... geen idee waarom :(
		//cout << (*itModules)->getName() << " has " << (*itModules)->getTeacherName() << " as teacher" << endl;
		itModules++;
	}
	cout << endl;

	//print total ecs for each student:
	cout << "Students with ecs -------------" << endl;
	itStudents = students.begin();
	while (itStudents != students.end()) {//werkt ook niet, het aantal ecs klopt totaal niet...
		cout << (*itStudents)->getName() << " has " << (*itStudents)->getTotalECs() << " ECs" << endl;
		itStudents++;
	}
	cout << endl;

	//tell a nice story:
	cout << "You hear rumours about Game Art changing to a value of only 1 EC" << endl << endl;
	cout << "Press a key to continue..." << endl << endl;

	//reassign 1 ec to game art
	coreArt->assignECs(1);

	//pause the 'game'
	cin.get();

	//print total ecs for each student again:
	cout << "Students with ecs -------------" << endl;
	itStudents = students.begin();
	while (itStudents != students.end()) {
		cout << (*itStudents)->getName() << " has " << (*itStudents)->getTotalECs() << " ECs" << endl;
		itStudents++;
	}
	cout << endl;

	cin.get();

	return 0;
}