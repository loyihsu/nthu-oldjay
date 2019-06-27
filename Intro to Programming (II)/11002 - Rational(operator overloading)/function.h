#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
    friend std::ostream &operator<<(std::ostream &, const Rational &);
public:
    Rational( int = 0, int = 1 ); // default constructor
    Rational operator+( const Rational & ) const; // function addition
    Rational operator-( const Rational & ) const; // function subtraction
    Rational operator*( const Rational & ) const; // function multi.
    Rational operator/( const Rational & ) const; // function division
    //void printRational () const; // print rational format
private:
    int numerator; // integer numerator
    int denominator; // integer denominator
    void reduce();
}; // end class Rational
#endif

