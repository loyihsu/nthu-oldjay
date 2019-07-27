#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
class Polynomial {
    friend std::ostream &operator<<(std::ostream &, const Polynomial &);
public:
    Polynomial();
    Polynomial(const int &, const int [51]);
    Polynomial operator+( const Polynomial & ) const; // addition
    Polynomial operator-( const Polynomial & ) const; // subtraction
    Polynomial operator*( const Polynomial & ) const; // multiplication
private:
    int coefficients[101];
    int greatestPower;
}; // end class Polynomial

#endif

