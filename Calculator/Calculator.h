#include <sstream>
#include <string>
#include "MyStack.h"
#include "functions.h"


class Calculator {
public:
    void processExpression(std::string _expression) {
        expression = _expression;
    }

    std::string getExpression() {
        return expression;
    }

    bool isExpressionCorrect(std::string _expression) {
        std::string newExpression;
        int openBrackets = 0;
        for (char c : _expression) {
            if (c > '9' && c != '+' && c != '-' && c != '/' && c != '*' && c != '^' && c != ' ') {
                return false;
            }
            if (!isspace(c)) {
                newExpression += c;
            }
        }
        for (int i = 0; i < newExpression.length(); ++i) {
            if (newExpression[i] == ')') {
                if (openBrackets == 0) {
                    return false;
                }
                else {
                    --openBrackets;
                }
            }
            if (newExpression[i] == '(') {
                ++openBrackets;
                if (i > 0 && newExpression[i - 1] != '+' && newExpression[i - 1] != '-' && newExpression[i - 1] != '/' &&
                    newExpression[i - 1] != '*' && newExpression[i - 1] != '^') {
                    return false;
                }

            }
            if (i > 0 && ((newExpression[i] == '+' || newExpression[i] == '-' || newExpression[i] == '/' ||
                newExpression[i] == '*' || newExpression[i] == '^') &&
                (newExpression[i - 1] == '+' || newExpression[i - 1] == '-' || newExpression[i - 1] == '/' ||
                    newExpression[i - 1] == '*' || newExpression[i - 1] == '^'))) {
                return false;
            }
            if (newExpression.length() == 1 && (newExpression[i] == '+' || newExpression[i] == '-' || newExpression[i] == '/' ||
                newExpression[i] == '*' || newExpression[i] == '^')) {
                return false;
            }
     
        }
        if (openBrackets == 0) {
            return true;
        }
        return false;
    }

    double calculation() {
        int flag = 1;
        for (int i = 0; i < expression.length();) {
            if (expression[i] == ' ') {
                ++i;
                continue;
            }
            if ((expression[i] >= '0') && (expression[i] <= '9') || (expression[i] == '-') && flag == 1) {
                std::stringstream ss;
                if (expression[i] == '-') {
                    ss << '-';
                    ++i;
                }
                while ((expression[i] >= '0') && (expression[i] <= '9') || (expression[i] == '.')) {
                    ss << expression[i];
                    ++i;
                }
                double number;
                ss >> number;
                Numbers << number;
                flag = 0;
                continue;
            }
            if (expression[i] == '+' || (expression[i] == '-') && (flag == 0) || expression[i] == '*' || expression[i] == '/' || expression[i] == '^') {
                if (Operators.isEmpty()) {
                    Operators << expression[i];
                    ++i;
                    continue;
                }
                if (!Operators.isEmpty() && (getPriority(expression[i]) > getPriority(Operators.getTop()))) {
                    Operators << expression[i];
                    ++i;
                    continue;
                }
                if (!Operators.isEmpty() && getPriority(expression[i]) <= getPriority(Operators.getTop())) {
                    math(Numbers, Operators);
                    continue;
                }
            }
            if (expression[i] == '(') {
                Operators << expression[i];
                flag = 1;
                ++i;
                continue;
            }
            if (expression[i] == ')') {
                while (Operators.getTop() != '(') {
                    math(Numbers, Operators);
                }
                Operators.pop();
                ++i;
                continue;
            }
        }
        while (!Operators.isEmpty()) {
            math(Numbers, Operators);
        }
        return  Numbers.getTop();
    }
private:
    Stack<double> Numbers;
    Stack<char> Operators;
    std::string expression;
};
