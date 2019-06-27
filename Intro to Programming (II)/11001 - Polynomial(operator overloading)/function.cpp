// Problem: http://140.114.86.238/problem/11001
#include <iostream>
#include <string>
#include "function.h"

std::ostream &operator<<(std::ostream &os, const Polynomial &pol)
{
    int i;
    for (i = pol.greatestPower; i >= 0 ; i--)
    {
        os << pol.coefficients[i];
        if (i != 0)
            os << " ";
    }
    return os;
}

Polynomial::Polynomial()
{
    int i;
    
    for (i = 0 ; i < 101; i++)
        coefficients[i] = 0;
    greatestPower = 0;
}

Polynomial::Polynomial(const int &gp, const int array[51])
{
    int i;
    
    for (i = 0 ; i < 101; i++)
        coefficients[i] = 0;
    greatestPower = gp;
    
    for (i = 0; i <= gp; i++)
        coefficients[i] = array[i];
}

Polynomial Polynomial::operator+( const Polynomial &ee ) const
{
    Polynomial output;
    int i;
    
    output.greatestPower = (greatestPower > ee.greatestPower) ? greatestPower : ee.greatestPower;
    
    for (i = 0; i <= output.greatestPower; i++)
        output.coefficients[i] = coefficients[i] + ee.coefficients[i];
    
    return output;
}

Polynomial Polynomial::operator-( const Polynomial &ee ) const
{
    Polynomial output;
    int i;
    
    output.greatestPower = (greatestPower > ee.greatestPower) ? greatestPower : ee.greatestPower;
    
    for (i = 0; i <= output.greatestPower; i++)
        output.coefficients[i] = coefficients[i] - ee.coefficients[i];
    
    return output;
}

Polynomial Polynomial::operator*( const Polynomial &ee ) const
{
    Polynomial output;
    int i, j;
    
    output.greatestPower = greatestPower + ee.greatestPower;
    
    for (i = 0; i <= greatestPower; i++)
        for (j = 0; j <= ee.greatestPower; j++)
            output.coefficients[i+j] += coefficients[i] * ee.coefficients[j];
    
    return output;
}