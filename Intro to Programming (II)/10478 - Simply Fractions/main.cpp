// Problem: http://140.114.86.238/problem/10478/
#include <stdio.h>
#include <iostream>
#include <vector>

struct fraction
{
    long long int d;
    long long int n;
};

int gcd(long long int a, long long int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void reduce (long long int &num, long long int &den)
{
    long long int GCD = gcd(num, den);
    
    long long int absnum = (num < 0)? num * (-1): num;
    long long int absden = (den < 0)? den * (-1): den;
    long long int smaller = (absnum <= absden)? absnum : absden;

    
    num /= GCD;
    den /= GCD;
    
    if (den < 0)
    {
        den *= -1;
        num *= -1;
    }
}

long long int SGS (long long int a, long long int b)
{
    long long int abs_a = (a < 0)? a * (-1): a;
    long long int abs_b = (a < 0)? b * (-1): b;
    long long int smaller = (a <= b)? a : b;
    long long int GCD = gcd (a, b);
    
    return (abs_a*abs_b)/GCD;
}

int main(void)
{
    //freopen("/Users/loyi/ownCloud/CPP/input", "r", stdin);
    
    long long int t;
    std::vector<fraction> frac;
    
    while (std::cin >> t)
    {
        frac.clear();
        
        long long int num = 0, den = 1;
        
        while (t--)
        {
            fraction temp;
            std::cin >> temp.n;
            std::cin >> temp.d;
            frac.push_back(temp);
        }
    
        num = 0, den = 1;
    
        for (auto f : frac)
        {
            den = SGS(den, f.d);
        }

        for (auto f : frac)
        {
            num += (f.n * (den / f.d));
        }
    
        reduce(num, den);
    
        std::cout << num << "/" << den << "\n";
    }
    return 0;
}