#pragma once
#include "Student.h"

class FirstSessionStudent : public Student{
public:
    FirstSessionStudent(char* _name, int _course, int _group, int _num_of_record, int* frst_marks);
    FirstSessionStudent(const FirstSessionStudent &other); 
    int getMark(int position) const;
    void setMark(int newMark, int position);
    float averageMark() const override; 
protected:
    int first_session_marks[4];
};