// Problem: http://140.114.86.238/problem/11002/
#include <iostream>
#include "function.h"

std::ostream &operator<<(std::ostream &os, const Rational &rat)
{
    os << rat.numerator << "/" << rat.denominator;
    return os;
}

Rational::Rational(int num, int den)
{
    numerator = num;
    denominator = den;
    reduce();
}

int abs_val(int a)
{
    if (a < 0)
        a *= -1;
    
    return a;
}

int dgi(int a, int b)
{
    int output = 1;
    
    for (int i = 1; i <= ((abs_val(a) < abs_val(b))? abs_val(a) : abs_val(b)); i++)
    {
        if (a % i == 0 && b % i == 0)
            output = i;
    }
    return output;
}

int sgb(int a, int b)
{
    return (abs_val(a) * abs_val(b))/dgi(a, b);
}

Rational Rational::operator+( const Rational &ee ) const
{
    int a = 1, b = 1;
    Rational output;
    if (denominator == ee.denominator)
    {
        output.denominator = denominator;
    } else {
        output.denominator = sgb(denominator, ee.denominator);
        a = output.denominator/denominator;
        b = output.denominator/ee.denominator;
    }
    
    output.numerator = numerator * a + ee.numerator * b;
    output.reduce();
    
    return output;
}

Rational Rational::operator-( const Rational &ee ) const
{
    int a = 1, b = 1;
    Rational output;
    if (denominator == ee.denominator)
    {
        output.denominator = denominator;
    } else {
        output.denominator = sgb(denominator, ee.denominator);
        a = output.denominator/denominator;
        b = output.denominator/ee.denominator;
    }
    
    output.numerator = numerator * a - ee.numerator * b;
    output.reduce();
    
    return output;
}

Rational Rational::operator*( const Rational &ee ) const
{
    Rational output;
    output.numerator = numerator * ee.numerator;
    output.denominator = denominator * ee.denominator;
    output.reduce();
    
    return output;
}

Rational Rational::operator/( const Rational &ee ) const
{
    Rational output;
    output.numerator = numerator * ee.denominator;
    output.denominator = denominator * ee.numerator;
    output.reduce();
    
    return output;
}

void Rational::reduce()
{
    if (denominator < 0)
    {
        denominator *= -1;
        numerator *= -1;
    }
    int dgis = dgi(denominator, numerator);
    denominator /= dgis;
    numerator /= dgis;
}