// Problem: http://140.114.86.238/problem/10557
#include "function.h"
#include <iostream>

Rational::Rational(int num, int denum)
{
    numerator = num;
    denominator = denum;
    reduce();
    return;
}

int abs_val(int a)
{
    if (a < 0)
        a *= -1;
    
    return a;
}

int lar_g(int numerator, int denominator)
{
    int bigger = (abs_val(numerator) >= abs_val(denominator))? abs_val(numerator): abs_val(denominator), temp = 1, i;
    
    for (i = 2; i <= bigger; i++)
    {
        if (numerator%i == 0 && denominator%i == 0)
            temp = i;
    }
    
    return temp;
}

int lcm(int a, int b)
{
    int output;
    
    output = (abs_val(a) * abs_val(b))/(lar_g(a, b));
    
    return output;
}

void Rational::reduce()
{
    int temp;
    if (denominator < 0)
    {
        numerator *= -1;
        denominator *= -1;
    }
    
    temp = lar_g(numerator, denominator);
    
    numerator /= temp;
    denominator /= temp;
    
    return;
}

Rational Rational::addition(const Rational &addee) const
{
    Rational output;
    int temp, a = 1, b = 1;
    
    if (denominator != addee.denominator)
    {
        temp = lcm(denominator,addee.denominator);
        output.denominator = temp;
        a = temp / denominator;
        b = temp / addee.denominator;
    } else output.denominator = denominator;
    
    output.numerator = a * numerator + b * addee.numerator;
    
    output.reduce();
    
    return output;
}

Rational Rational::subtraction(const Rational &subee) const
{
    Rational output;
    int temp, a = 1, b = 1;
    
    if (denominator != subee.denominator)
    {
        temp = lcm(denominator,subee.denominator);
        output.denominator = temp;
        a = temp / denominator;
        b = temp / subee.denominator;
    } else output.denominator = denominator;
    
    output.numerator = a * numerator - b * subee.numerator;
    
    output.reduce();
    
    return output;
}

Rational Rational::multiplication(const Rational &mulee) const
{
    Rational output;
    
    output.denominator = denominator * mulee.denominator;
    output.numerator = numerator * mulee.numerator;
    
    output.reduce();
    
    return output;
}

Rational Rational::division(const Rational &divee) const
{
    Rational output;
    
    output.denominator = denominator * divee.numerator;
    output.numerator = numerator * divee.denominator;
    
    output.reduce();
    
    return output;
}

void Rational::printRational() const
{
    std::cout << numerator << "/" << denominator;
    return;
}

