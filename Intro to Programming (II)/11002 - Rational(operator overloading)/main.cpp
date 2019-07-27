#include <iostream>
#include "function.h" // include definition of class Rational
using namespace std;

int main() {
    char s1;
    int s2, s3, s4, s5;
    Rational x;

    while(cin >>s1>>s2>>s3>>s4>>s5) {
        if(cin.eof())
            break;

        Rational c(s2, s3), d(s4, s5);

        if(s1 == '+') {
            x = c + d;
            cout<< x <<endl;
        } else if(s1 == '-') {
            x = c - d;
            cout<< x <<endl;
        } else if(s1 == '*') {
            x = c * d;
            cout<< x <<endl;
        } else if(s1 == '/') {
            x = c / d;
            cout<< x <<endl;
        }
    }
} // end main
