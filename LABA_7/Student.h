#pragma once
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <typeinfo>

class Student{
public:
    Student(char* _name, int _course, int _group, int _num_of_record);
    Student(const Student &other);
    int getNumOfRecord() const;
    int getIndex() const;
    int getCourse() const;
    void setCourse(int _course);
    int getGroup() const;
    void setGroup(int _group);
    char* getName() const;
    void setName(char* _name);
    virtual float averageMark() const;
    ~Student();
private:
    Student() = default;
    char* name;
    int course;
    int group;
    int index;
    int num_of_record;
};

