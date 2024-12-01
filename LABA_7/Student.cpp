#include "Student.h"


int newIndex = std::rand();

    Student::Student(char* _name, int _course, int _group, int _num_of_record)
            : course(_course), group(_group), num_of_record(_num_of_record){
        name = new char[100];
        std::strcpy(name, _name);
        index = newIndex;
        newIndex++;
    }

    Student::Student(const Student &other){
        this->course = other.course;
        this->group = other.group;
        this->num_of_record = other.num_of_record;
        std::strcpy(name, other.name);
        this->index = other.index;
    }

    int Student::getNumOfRecord() const{
        return num_of_record;
    }

    int Student::getIndex() const{
        return index;
    }

    int Student::getCourse() const{
        return course;
    }

    void Student::setCourse(int _course){
        this->course = _course;
    }

    int Student::getGroup() const{
        return group;
    }

    void Student::setGroup(int _group){
        this->course = _group;
    }

    char* Student::getName() const{
        return this->name;
    }

    void Student::setName(char* _name){
        strcpy(name, _name);
    }

    float Student::averageMark() const{
        return 0;
    }

    Student::~Student(){
        delete[] name;
    }
    
