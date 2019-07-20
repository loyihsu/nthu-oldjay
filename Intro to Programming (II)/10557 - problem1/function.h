#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
public:
    Rational( int = 0, int = 1 ); // default constructor
    Rational addition( const Rational & ) const; // function addition
    Rational subtraction( const Rational & ) const; // function subtraction
    Rational multiplication( const Rational & ) const; // function multi.
    Rational division( const Rational & ) const; // function division
    void printRational () const; // print rational format
private:
    int numerator; // integer numerator
    int denominator; // integer denominator
    void reduce();
}; // end class Rational

#endif
