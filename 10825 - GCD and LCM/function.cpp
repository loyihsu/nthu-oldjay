// Problem: http://140.114.86.238/problem/10825/
#include <stdio.h>
#include "function.h"

int gcd(int a,int b) {
    return (b == 0) ? a : gcd(b, a%b); 
}

int lcm(int a,int b) {
    return a*b/gcd(a,b);
}
