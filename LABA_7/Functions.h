#pragma once
#include "SecondSessionStudent.h"

float averageMarkOfGroupAfterFirstSession(std::vector<Student*> allStudents, int group);
float averageMarkOfGroupAfterSecondSession(std::vector<Student*> allStudents, int group);
float averageMarkOfGroup(std::vector<Student*> allStudents, int group);
std::ostream& operator<<(std::ostream &stream, const Student &a);
std::ostream& operator<<(std::ostream &stream, const FirstSessionStudent &a);
std::ostream& operator<<(std::ostream &stream, const SecondSessionStudent &a);