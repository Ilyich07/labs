#include "FirstSessionStudent.h"


    FirstSessionStudent::FirstSessionStudent(char* _name, int _course, int _group, int _num_of_record, int* frst_marks)
    : Student(_name,  _course, _group, _num_of_record){
    for (int i = 0; i < 4; ++i){
        first_session_marks[i] = frst_marks[i];
        } 
    }

    FirstSessionStudent::FirstSessionStudent(const FirstSessionStudent &other) : Student (other){
        for(int i = 0; i < 4; ++i){
            this->first_session_marks[i] = other.first_session_marks[i];
        }
    }

    int FirstSessionStudent::getMark(int position) const{
        return first_session_marks[position];
    }

    void FirstSessionStudent::setMark(int newMark, int position){
        first_session_marks[position] = newMark;
    }

    float FirstSessionStudent::averageMark() const{
        float sumOfMarks = 0;
        for (int i = 0; i < 4; ++i){
            sumOfMarks += first_session_marks[i];
        }
        return sumOfMarks/4;
    }