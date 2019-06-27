#ifndef SIMPLESTRING_H
#define SIMPLESTRING_H
#include <iostream>

class SimpleString
{
public:
    SimpleString( char* = NULL, int = 0 ); // default constructor
    SimpleString( const SimpleString & ); // copy constructor
    ~SimpleString(); // destructor
    const SimpleString &operator=( const SimpleString & ); // assignment operator
    bool operator==( const SimpleString & ) const; // equality operator
    void reverse(); // reverse the string
private:
    size_t size; // pointer-based string size
    char *ptr; // pointer to first element of pointer-based string
}; // end class SimpleString
class PalindromeChecker
{
public:
    PalindromeChecker(const SimpleString &s)
    {
        str = s;
        rev = s;
        rev.reverse();
    };
    void isPalindrome()
    {
        if(rev == str)
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    };
private:
    SimpleString str;
    SimpleString rev;
};

#endif

