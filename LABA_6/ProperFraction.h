#pragma once
#include <iostream>
#include <cmath>

class ProperFraction
{
public:
    ProperFraction(int _numerator, int _denominator);
    ProperFraction(const ProperFraction &b);
    void reduceFraction();
    int getNumerator() const;
    int getDenominator() const;
    ProperFraction operator+ (const ProperFraction &b);
    ProperFraction operator* (const ProperFraction &b);
    ProperFraction operator/ (const ProperFraction &b);
private:
    int numerator;
    int denominator;
    ProperFraction() = default;
};

std::ostream& operator<< (std::ostream& out, const ProperFraction &b);

