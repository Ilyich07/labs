#include <iostream>
#include "Calculator.h"

int main() {
    Calculator Calculator;
    std::string expression;
    std::cout << "Input expression: ";
    std::getline(std::cin, expression);
    if (Calculator.isExpressionCorrect(expression)) {
        Calculator.processExpression(expression);
        std::cout << "Answer: " << Calculator.calculation();
    }
    else {
        std::cout << "Your expression is incorrect!";
    }
}