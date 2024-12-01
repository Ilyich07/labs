#include "SecondSessionStudent.h"

    SecondSessionStudent::SecondSessionStudent(char* _name, int _course, int _group, int _num_of_record, int* frst_marks, int* scd_marks)
    : FirstSessionStudent(_name,_course, _group, _num_of_record, frst_marks){
        for(int i = 0; i < 5; ++i){
            second_session_marks[i] = scd_marks[i];
        }
    }

    SecondSessionStudent::SecondSessionStudent(const SecondSessionStudent &other) : FirstSessionStudent (other){
        for(int i = 0; i < 5; ++i){
            this->second_session_marks[i] = other.second_session_marks[i];
        }
    }

    int SecondSessionStudent::getMark(int session, int position) const{
        if (session == 1){
            return first_session_marks[position];
        }
        if (session == 2){
            return second_session_marks[position];
        }
        return 0;
    }
    
    void SecondSessionStudent::setMark(int session, int position, int newMark){
        if (session == 1){
            first_session_marks[position] = newMark;
        }
        if (session == 2){
            second_session_marks[position] = newMark;
        }
    }

    float SecondSessionStudent::averageMark() const{
        float sumOfMarks = 0;
        for (int i = 0; i < 4; ++i){
            sumOfMarks += first_session_marks[i];
        }
        for (int i = 0; i < 5; ++i){
            sumOfMarks += second_session_marks[i];
        }
        return sumOfMarks/9;
    }
