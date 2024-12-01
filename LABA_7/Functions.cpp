#include "Functions.h"

float averageMarkOfGroupAfterFirstSession(std::vector<Student*> allStudents, int group){
    float sumOfMarks = 0;
    int count=0;
    for (Student* student: allStudents) {
        if((student->getGroup() == group) && dynamic_cast<FirstSessionStudent*>(student)){
           count +=1;
           for (int i = 0; i < 4; ++i){
            sumOfMarks += ((FirstSessionStudent*)student)->getMark(i);
           }
        }
    }
    if (count){
        return sumOfMarks/(count*4);
    }
    return 0;
}

float averageMarkOfGroupAfterSecondSession(std::vector<Student*> allStudents, int group){
    float sumOfMarks = 0;
    int count=0;
    for (Student* student: allStudents) {
        if((student->getGroup() == group) && dynamic_cast<SecondSessionStudent*>(student)){
           count +=1;
           for (int i = 0; i < 5; ++i){
            sumOfMarks += ((SecondSessionStudent*)student)->getMark(2, i);
           }
        }
    }
    if (count){
        return sumOfMarks/(count*5);
    }
    return 0;
}


float averageMarkOfGroup(std::vector<Student*> allStudents, int group){
    float sumOfMarks = 0;
    int count=0;
    for (Student* student: allStudents) {
        if(dynamic_cast<FirstSessionStudent*>(student)){
            count +=4;
            for (int i = 0; i < 4; ++i){
                sumOfMarks += ((FirstSessionStudent*)student)->getMark(i);
           }
        }
        if(dynamic_cast<SecondSessionStudent*>(student)){
            count +=5;
            for (int i = 0; i < 5; ++i){
                sumOfMarks += ((SecondSessionStudent*)student)->getMark(2, i);
           }
        }
    }
    if (count){
        return sumOfMarks/count;
    }
    return 0;
}

std::ostream& operator<<(std::ostream &stream, const Student &a){
    stream<< "Name: "<< a.getName()<< std::endl << "Group: "<< a.getGroup() << std::endl;
    stream<<"Course: "<< a.getCourse()<< std::endl << "Number of record book: "<<a.getNumOfRecord()<< std::endl;
    stream<< "Index: "<< a.getIndex()<< std::endl;
    return stream;
};


std::ostream& operator<<(std::ostream &stream, const FirstSessionStudent &a){
        stream<< "Name: "<< a.getName()<< std::endl << "Group: "<< a.getGroup() << std::endl;
        stream<<"Course: "<< a.getCourse() << "Number of record book: "<<a.getNumOfRecord()<< std::endl<< "Index: "<< a.getIndex()<< std::endl;
        stream<< "Marks for the first session: ";
        for (int i = 0; i < 4; ++i){
            stream<<a.getMark(i)<< " ";
        }
        return stream;
    }

std::ostream& operator<<(std::ostream &stream, const SecondSessionStudent &a){
        stream<< "Name: "<< a.getName()<< std::endl << "Group: "<< a.getGroup() << std::endl;
        stream<<"Course: "<< a.getCourse() << std::endl << "Number of record book: "<<a.getNumOfRecord()<< std::endl;
        stream<< "Index: "<< a.getIndex()<< std::endl;
        stream<< "Marks for the first session: ";
        for (int i = 0; i < 4; ++i){
            stream<<a.getMark(1, i)<< " ";
        }
        stream<< std::endl;
        stream<< "Marks for the second session: ";
        for (int i = 0; i < 5; ++i){
            stream<<a.getMark(2, i)<< " ";
        }
        return stream;
    };