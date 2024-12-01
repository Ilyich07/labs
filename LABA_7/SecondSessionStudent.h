#pragma once
#include "FirstSessionStudent.h"

class SecondSessionStudent : public FirstSessionStudent{
public:
    SecondSessionStudent(char* _name, int _course, int _group, int _num_of_record, int* frst_marks, int* scd_marks);
    SecondSessionStudent(const SecondSessionStudent &other);
    int getMark(int session, int position) const;
    void setMark(int session, int position, int newMark);
    float averageMark() const; 
protected:
    int second_session_marks[5];
};