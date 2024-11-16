#include "ProperFraction.h"

ProperFraction::ProperFraction(int _numerator, int _denominator){  
    while (_denominator == 0){
        std::cout<< "The denominator of a fraction cannot be zero. Enter a different value:  ";
        std::cin>>_denominator;
    }
    this->numerator = _numerator;
    this->denominator = _denominator;
    this->reduceFraction();
}

ProperFraction::ProperFraction(const ProperFraction &b){
    this->numerator = b.numerator;
    this->denominator = b.denominator;
}

void ProperFraction::reduceFraction(){
    int a = abs(this->numerator);
    int c = abs(this->denominator);
    while((a != 0) && (c != 0)){
        if (a >= c){
            a %= c;
        } else {
            c %= a;
        }
    }
    this->numerator /= a + c;
    this->denominator /= a + c;
}

ProperFraction ProperFraction::operator+ (const ProperFraction &b){
    int newDenominator = this->denominator * b.denominator;
    int newNumerator = this->numerator * b.denominator + b.numerator * this->denominator;
    ProperFraction c( newNumerator, newDenominator);
    c.reduceFraction();
    return c;
    }

ProperFraction ProperFraction::operator* (const ProperFraction &b){
    int newNumerator = this->numerator *  b.numerator;
    int newDenominator = this->denominator * b.denominator;
    ProperFraction c( newNumerator, newDenominator);
    c.reduceFraction();
    return c;
}

ProperFraction ProperFraction::operator/ (const ProperFraction &b){
    int newNumerator = this->numerator *  b.denominator;
    int newDenominator = this->denominator * b.numerator;
    ProperFraction c( newNumerator, newDenominator);
    c.reduceFraction();
    return c;
}

int ProperFraction::getNumerator() const {
    return this->numerator;
}

int ProperFraction::getDenominator() const {
    return this->denominator;
}

std::ostream& operator<< (std::ostream& out, const ProperFraction &b){
    if (((b.getNumerator() > 0) && (b.getDenominator() < 0)) || ((b.getNumerator() < 0) && (b.getDenominator() > 0))){
            out << " -";
    }
    if (abs(b.getNumerator()) == abs(b.getDenominator())){
        out<< "1";
        return out;
    }
    if (abs(b.getNumerator()) == 0){
        out<< "0";
        return out;
    }
    if (abs(b.getNumerator()) > abs(b.getDenominator())){
        out <<abs(b.getNumerator()) / abs(b.getDenominator())<< "  ";
        out<< abs(b.getNumerator() % b.getDenominator()) <<"/"<< abs(b.getDenominator());
    } else {
        out << abs(b.getNumerator()) << "/" << abs(b.getDenominator());
        }
        return out;
}