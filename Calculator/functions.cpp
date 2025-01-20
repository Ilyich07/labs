#include <stdexcept> 
#include <cmath>
#include "functions.h"

void math(Stack<double>& Numbers, Stack<char>& Operators) {
    double rightOperand;
    double leftOperand;
    char operation;
    Numbers >> leftOperand;
    Numbers >> rightOperand;
    Operators >> operation;
    switch (operation) {
    case '+':
        double c;
        c = rightOperand + leftOperand;
        Numbers << c;
        break;
    case '-': Numbers << rightOperand - leftOperand; break;
    case '*': Numbers << rightOperand * leftOperand; break;
    case '^': Numbers << pow(rightOperand, leftOperand); break;
    case '/':
        if (leftOperand == 0) {
            throw std::runtime_error("You can't divide by zero!");
        }
        Numbers << rightOperand / leftOperand; break;
    }
}

int getPriority(char operation) {
    if (operation == '+' || operation == '-') {
        return 1;
    }
    if (operation == '*' || operation == '/') {
        return 2;
    }
    if (operation == '^') {
        return 3;
    }
    return 0;
}