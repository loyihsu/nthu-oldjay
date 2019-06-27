// Problem: http://140.114.86.238/problem/10993
#include <stdio.h>
#include "function.h"
#include <iostream>

Polynomial::Polynomial()
{
    int i;
    for (i = 0; i < 101; i++)
        coefficients[i] = 0;
    greatestPower = 0;
}

Polynomial::Polynomial(const int a, const int b[51])
{
    int i;
    for (i = 0; i < 101; i++)
        coefficients[i] = 0;
    for (i = 0; i <= a; i++)
        coefficients[i] = b[i];
    greatestPower = a;
}

Polynomial Polynomial::add(const Polynomial addee) const
{
    //MARK: Declare
    Polynomial output;
    int gp2, i;
    
    //MARK: Initialize
    output = Polynomial();
    gp2 = (greatestPower >= addee.greatestPower)? greatestPower:addee.greatestPower;
    
    //MARK: Action
    for (i = gp2; i >= 0; i--)
    {
        output.coefficients[i] = coefficients[i] + addee.coefficients[i];
    }
    output.greatestPower = gp2;
    
    return output;
}

Polynomial Polynomial::subtract(const Polynomial subee) const
{
    //MARK: Declare
    Polynomial output;
    int gp2, i;
    
    //MARK: Initialize
    output = Polynomial();
    gp2 = (greatestPower >= subee.greatestPower)? greatestPower:subee.greatestPower;
    
    //MARK: Action
    for (i = gp2; i >= 0; i--)
        output.coefficients[i] = coefficients[i] - subee.coefficients[i];
    output.greatestPower = gp2;
    
    return output;
}

Polynomial Polynomial::multiplication(const Polynomial mulee) const
{
    //MARK: Declare
    Polynomial output;
    int i, j;
    
    //MARK: Initialize
    output = Polynomial();
    
    //MARK: Action
    for (i = 0; i <= greatestPower; i++)
    {
        for (j = 0; j <= mulee.greatestPower; j++)
        {
            output.coefficients[i+j] += coefficients[i] * mulee.coefficients[j];
        }
    }
    output.greatestPower = greatestPower + mulee.greatestPower;
    
    return output;
}

void Polynomial::output() const
{
    int i;
    for (i = greatestPower; i >= 0; i--)
    {
        std::cout << coefficients[i];
        if (i != 0)
            std::cout << " ";
        //else
        //std::cout << "\n";
    }
}
