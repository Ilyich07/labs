#include "Student.h"
#include "FirstSessionStudent.h"
#include "SecondSessionStudent.h"
#include "Functions.h"


int main(){
    int marks1[] = {8, 8, 9, 9};
    int marks2[] = {8, 8, 6, 6};
    int marks3[] = {4, 4, 5, 5, 5};
    int marks4[] = {4, 4, 4, 4};
    int marks5[] = {3, 3, 3, 3, 3};
    Student* ptrA = new FirstSessionStudent( "Sam", 1, 4, 13213123, marks1);
    Student* ptrB = new FirstSessionStudent( "Frank", 2, 4, 231223, marks2);
    Student* ptrC = new SecondSessionStudent( "Frank", 2, 4, 231223, marks4, marks3);
    Student* ptrF = new SecondSessionStudent( "Frank", 2, 4, 231223, marks4, marks5);
    std::cout<< *ptrA<< std::endl<< std::endl;
    std::cout<< *ptrB<< std::endl<< std::endl;
    std::cout<< ptrB->averageMark()<<std::endl;
    std::cout<< ptrA->averageMark()<<std::endl;
    std::vector<Student*> allStudents {ptrA, ptrB, ptrC, ptrF};
    std::cout<<averageMarkOfGroupAfterFirstSession(allStudents, 4)<<std::endl;
    std::cout<<averageMarkOfGroupAfterSecondSession(allStudents, 4)<<std::endl;
    std::cout<<averageMarkOfGroup(allStudents, 4)<<std::endl;
    delete ptrA;
    delete ptrB;
    delete ptrC;
    delete ptrF;
}