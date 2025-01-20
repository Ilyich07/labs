#include "pch.h"
#include "..//Calculator//Calculator.h"
#include "..//Calculator//MyStack.h"
#include "..//Calculator//functions.h"
#include "..//Calculator//functions.cpp"

class CalculatorTest : public testing::Test {
protected:
	Calculator Calc;
};

class MyStackTest : public testing::Test {
protected:
	void SetUp() override {
		intStack2 << 1;
		charStack2 << '+' << '-';
	}
	Stack<int> intStack1;
	Stack<int> intStack2;
	Stack<char> charStack1;
	Stack<char> charStack2;
};


TEST_F(MyStackTest, isEmpty) {
	EXPECT_EQ(intStack1.isEmpty(), true);
	EXPECT_EQ(intStack2.isEmpty(), false);
	EXPECT_EQ(charStack1.isEmpty(), true);
	EXPECT_EQ(charStack2.isEmpty(), false);
}

TEST_F(MyStackTest, getSize) {
	EXPECT_EQ(intStack1.getSize(), 0);
	EXPECT_EQ(intStack2.getSize(), 1);
	EXPECT_EQ(charStack1.getSize(), 0);
	EXPECT_EQ(charStack2.getSize(), 2);
}


TEST_F(MyStackTest, Pop) {
	EXPECT_THROW(intStack1.pop(), std::runtime_error);
	intStack2.pop();
	EXPECT_EQ(intStack2.isEmpty(), true);
	EXPECT_THROW(charStack1.pop(), std::runtime_error);
	charStack2.pop();
	EXPECT_EQ(charStack2.getTop(), '+');
}

TEST_F(MyStackTest, getTop) {
	EXPECT_THROW(intStack1.getTop(), std::runtime_error);
	EXPECT_EQ(intStack2.getTop(), 1);
	EXPECT_THROW(charStack1.getTop(), std::runtime_error);
	EXPECT_EQ(charStack2.getTop(), '-');
}

TEST_F(MyStackTest, InputTest) {
	intStack1 << 1 << 2 << 3;
	EXPECT_EQ(intStack1.getSize(), 3);
	intStack1 << 52;
	EXPECT_EQ(intStack1.getTop(), 52);
	charStack1 << '@';
	EXPECT_EQ(charStack1.getTop(), '@');
	charStack2 << '&';
	EXPECT_EQ(charStack2.getTop(), '&');
}

TEST_F(MyStackTest, OutputTest) {
	int a;
	char b;
	EXPECT_THROW(intStack1 >> a, std::runtime_error);
	intStack2 >> a;
	EXPECT_EQ(intStack2.isEmpty(), true);
	EXPECT_THROW(charStack1 >> b, std::runtime_error);
	charStack2 >> b;
	EXPECT_EQ(charStack2.getSize(), 1);
}

TEST_F(MyStackTest, EqualityTest) {
	intStack1 << 1;
	EXPECT_EQ(intStack1 == intStack2, true);
	EXPECT_EQ(charStack1 == charStack2, false);
}

TEST_F(MyStackTest, CopyTest) {
	intStack1 = intStack2;
	EXPECT_EQ(intStack1.getSize(), 1);
	EXPECT_EQ(intStack1.getTop(), 1);
	charStack1 = charStack2;
	EXPECT_EQ(charStack1.getSize(), 2);
	EXPECT_EQ(charStack1.getTop(), '-');
}

TEST_F(MyStackTest, IninequalityTest) {
	EXPECT_EQ(intStack1 < intStack2, true);
	charStack1 << '+' << '1';
	EXPECT_EQ(intStack1 < intStack2, true);
}

TEST_F(MyStackTest, IndexTest) {
	EXPECT_THROW(intStack1[2], std::invalid_argument);
	EXPECT_EQ(intStack2[1], 1);
	EXPECT_THROW(charStack1[2], std::invalid_argument);
	EXPECT_EQ(charStack2[2], '-');
}

//Calculator

//ProcessExpression

TEST_F(CalculatorTest, ProcessExpressionTest1) {
	std::string str = "2+2";
	Calc.processExpression(str);
	EXPECT_EQ(Calc.getExpression(), str);
}

TEST_F(CalculatorTest, ProcessExpressionTest2) {
	std::string str = "+4925*90";
	Calc.processExpression(str);
	EXPECT_EQ(Calc.getExpression(), str);
}

TEST_F(CalculatorTest, ProcessExpressionTest3) {
	std::string str = "       ";
	Calc.processExpression(str);
	EXPECT_EQ(Calc.getExpression(), str);
}

//isExpressionCorrect

TEST_F(CalculatorTest, ExpressionCorrectTest1) {
	std::string str = "2+2";
	EXPECT_EQ(Calc.isExpressionCorrect(str), true);
}

TEST_F(CalculatorTest, ExpressionCorrectTest2) {
	std::string str = "2/1+5*9-3^5";
	EXPECT_EQ(Calc.isExpressionCorrect(str), true);
}

TEST_F(CalculatorTest, ExpressionCorrectTest3) {
	std::string str = "5 - 3 *   6";
	EXPECT_EQ(Calc.isExpressionCorrect(str), true);
}

TEST_F(CalculatorTest, ExpressionCorrectTest4) {
	std::string str = "(8*5)^3-(-6+3)";
	EXPECT_EQ(Calc.isExpressionCorrect(str), true);
}

TEST_F(CalculatorTest, ExpressionCorrectTest5) {
	std::string str = "(4+2";
	EXPECT_EQ(Calc.isExpressionCorrect(str), false);
}

TEST_F(CalculatorTest, ExpressionCorrectTest6) {
	std::string str = "5(4+3)";
	EXPECT_EQ(Calc.isExpressionCorrect(str), false);
}

TEST_F(CalculatorTest, ExpressionCorrectTest7) {
	std::string str = "7+3)";
		EXPECT_EQ(Calc.isExpressionCorrect(str), false);
}

TEST_F(CalculatorTest, ExpressionCorrectTest8) {
	std::string str = "3+-5";
	EXPECT_EQ(Calc.isExpressionCorrect(str), false);
}

TEST_F(CalculatorTest, ExpressionCorrectTest9) {
	std::string str = "t";
	EXPECT_EQ(Calc.isExpressionCorrect(str), false);
}

TEST_F(CalculatorTest, ExpressionCorrectTest10) {
	std::string str = "/";
	EXPECT_EQ(Calc.isExpressionCorrect(str), false);
}

//Calculation

TEST_F(CalculatorTest, Calculation1) {
	std::string str = "1+1";
	Calc.processExpression(str);
	EXPECT_EQ(Calc.calculation(), 2);
}

TEST_F(CalculatorTest, Calculation2) {
	std::string str = "1+1*2-3^2";
	Calc.processExpression(str);
	EXPECT_EQ(Calc.calculation(), -6);
}

TEST_F(CalculatorTest, Calculation3) {
	std::string str = "(8*8)^(1/2)";
	Calc.processExpression(str);
	EXPECT_EQ(Calc.calculation(), 8);
}

TEST_F(CalculatorTest, Calculation4) {
	std::string str = "-3*(-2*(2-1))";
	Calc.processExpression(str);
	EXPECT_EQ(Calc.calculation(), 6);
}

TEST_F(CalculatorTest, Calculation5) {
	std::string str = "-3^2";
	Calc.processExpression(str);
	EXPECT_EQ(Calc.calculation(), 9);
}

TEST_F(CalculatorTest, Calculation6) {
	std::string str = "7*(3-2)";
	Calc.processExpression(str);
	EXPECT_EQ(Calc.calculation(), 7);
}

TEST_F(CalculatorTest, Calculation7) {
	std::string str = "-1-11";
	Calc.processExpression(str);
	EXPECT_EQ(Calc.calculation(), -12);
}

TEST_F(CalculatorTest, Calculation8) {
	std::string str = "1+(-10)";
	Calc.processExpression(str);
	EXPECT_EQ(Calc.calculation(), -9);
}

TEST_F(CalculatorTest, Calculation9) {
	std::string str = "9";
	Calc.processExpression(str);
	EXPECT_EQ(Calc.calculation(), 9);
}

