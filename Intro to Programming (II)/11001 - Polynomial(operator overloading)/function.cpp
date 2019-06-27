// Problem: http://140.114.86.238/problem/11001
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include "function.h"

std::ostream &operator<<(std::ostream &os, const Polynomial &pol)
{
    for (int i = pol.greatestPower; i >= 0 ; i--)
    {
        if (i != pol.greatestPower)
            os << " " << pol.coefficients[i];
        else
            os << pol.coefficients[i];
    }
    return os;
}

Polynomial::Polynomial()
{
    int i;
    for (i = 0; i < 101; i++)
        coefficients[i] = 0;
    greatestPower = 0;
    
    return;
}

Polynomial::Polynomial(const int &power, const int arr[51])
{
    int i;
    for (i = 0; i < 101; i++)
        coefficients[i] = 0;
    greatestPower = 0;
    
    for (i = 0; i <= power; i++)
        coefficients[i] = arr[i];
    greatestPower = power;
    
    return;
}

Polynomial Polynomial::operator+(const Polynomial &plusee) const
{
    Polynomial output;
    int i;
    int greaterP = (greatestPower >= plusee.greatestPower)? greatestPower: plusee.greatestPower;
    
    for (i = 0; i <= greaterP; i++)
        output.coefficients[i] = coefficients[i] + plusee.coefficients[i];
    
    output.greatestPower = greaterP;
    
    return output;
}

Polynomial Polynomial::operator-(const Polynomial &minusee) const
{
    Polynomial output;
    
    int i;
    int greaterP = (greatestPower >= minusee.greatestPower)? greatestPower: minusee.greatestPower;
    
    for (i = 0; i <= greaterP; i++)
        output.coefficients[i] = coefficients[i] - minusee.coefficients[i];
    
    output.greatestPower = greaterP;
    
    return output;
}

Polynomial Polynomial::operator*(const Polynomial &mulee) const
{
    Polynomial output;
    int i, j;
    
    for (i = 0; i <= greatestPower; i++)
        for (j = 0; j <= mulee.greatestPower; j++)
            output.coefficients[i+j] += coefficients[i] * mulee.coefficients[j];
    
    output.greatestPower = greatestPower + mulee.greatestPower;
    
    return output;
}
