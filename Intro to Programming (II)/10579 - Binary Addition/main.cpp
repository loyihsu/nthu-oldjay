// Problem: http://140.114.86.238/problem/10579/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    std::ios::sync_with_stdio(false);
    
    int t;
    
    int n, i;
    
    std::vector<int> b1, b2;
    
    char temp;
    int t1, t2;
    
    while (std::cin >> t)
    {
        while (t--)
        {
            b1.clear();
            b2.clear();
            std::cin >> n;
            i = n;
            while (i--)
            {
                std::cin >> temp;
                t1 = temp - '0';
                b1.push_back(t1);
            }
        
            i = n;
            while (i--)
            {
                std::cin >> temp;
                t1 = temp - '0';
                b2.push_back(t1);
            }
            
            std::transform(b1.begin(), b1.end(), b2.begin(), b1.begin(), std::plus<int>());
            
            std::reverse(b1.begin(), b1.end());
            
            t1 = 0;
            
            
            for (auto &a: b1)
            {
                if (t1 != 0)
                    a += t1;
                t1 = a / 2;
                t2 = a % 2;
                
                a = t2;
            }
            
            std::reverse(b1.begin(), b1.end());
            
            for (auto a: b1)
            {
                std::cout << a;
            }
            
            std::cout << "\n";
        }
    }
    return 0;
}