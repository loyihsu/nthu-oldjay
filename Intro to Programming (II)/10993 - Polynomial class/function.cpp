// Problem: http://140.114.86.238/problem/10993
#include <iostream>
#include <stdio.h>
#include <string>
#include "function.h"

Polynomial::Polynomial(){
    int i;
    
    for (i = 0; i < 101; i++)
        coefficients[i] = 0;

    greatestPower = 0;
}

Polynomial::Polynomial(const int great, const int array[51]) {
    int i;
    
    for (i = 0; i < 101; i++)
        coefficients[i] = 0;
    
    greatestPower = great;
    
    for (i = 0; i <= great; i++)
        coefficients[i] = array[i];
}

Polynomial Polynomial::add( const Polynomial ee) const {
    Polynomial output;
    int i, gp = (greatestPower > ee.greatestPower)? greatestPower : ee.greatestPower;
    
    output.greatestPower = gp;
    
    for (i = 0; i <= gp; i++)
        output.coefficients[i] = coefficients[i] + ee.coefficients[i];
    
    return output;
}

Polynomial Polynomial::subtract( const Polynomial ee) const {
    Polynomial output;
    int i, gp = (greatestPower > ee.greatestPower)? greatestPower : ee.greatestPower;
    
    output.greatestPower = gp;
    
    for (i = 0; i <= gp; i++)
        output.coefficients[i] = coefficients[i] - ee.coefficients[i];
    
    return output;
}

Polynomial Polynomial::multiplication( const Polynomial ee) const {
    Polynomial output;
    int i, j;
    
    output.greatestPower = greatestPower + ee.greatestPower;
    
    for (i = 0; i <= greatestPower; i++)
        for (j = 0; j <= ee.greatestPower; j++)
            output.coefficients[i+j] += coefficients[i] * ee.coefficients[j];
    
    return output;
}

void Polynomial::output() const {
    int i;
    
    for (i = greatestPower; i >= 0; i--) {
        std::cout << coefficients[i];
        if (i != 0)
            std::cout << " ";
    }
}