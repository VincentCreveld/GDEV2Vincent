#include <iostream>
#include <string>
#include "Functions.h"
#include "Block.h"

using namespace std;

class Block {
	int lessonTime, weekNum, dayNum, lessonDuration;
	string fNameTeacher, lNameTeacher, classes, classroomNo, moduleName;
public:
	void SetValues(int, int, int, int, string, string, string, string, string);
};

void Block::SetValues(int _lessonTime, int _weekNum, int _dayNum, int _lessonDuration, string _fNameTeacher, string _lNameTeacher, string _classes, string _classroomNo, string _moduleNaam) {
	lessonTime = _lessonTime;
	weekNum = _weekNum;
	dayNum = _dayNum;
	lessonDuration = _lessonDuration;
	fNameTeacher = _fNameTeacher;
	lNameTeacher = _lNameTeacher;
	classes = _classes;
	classroomNo = _classroomNo;
}

