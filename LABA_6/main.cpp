#include <iostream>
#include "ProperFraction.h"

int main(){
    int _numerator;
    int _denominator;
    ProperFraction a(5, -3);
    ProperFraction b(2, 4);
    ProperFraction c = a + b;
    ProperFraction d = a * b;
    ProperFraction f = a / b;
    std::cout<< c <<std::endl << d << std::endl << f ;
}
