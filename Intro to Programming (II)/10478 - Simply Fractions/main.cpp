// Problem: http://140.114.86.238/problem/10478/
#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    std::ios::sync_with_stdio(false);
    long long testcases, i, temp1, temp2, od, on;
    std::vector<long long> num, den;
    
    while (std::cin >> testcases) {
        num.clear();
        den.clear();
        od = 1;
        on = 0;
        i = testcases;
        while (i--) {
            std::cin >> temp1 >> temp2;
            num.push_back(temp1);
            den.push_back(temp2);
        }
        
        for (auto d: den)
            od = (od * d)/std::__gcd(od, d);
        
        for (long long n = 0; n < num.size(); n++)
            on += num[n] * (od/den[n]);
        
        long long g = std::__gcd(od, on);
        od /= g;
        on /= g;
        
        if (od < 0) {
            od *= -1;
            on *= -1;
        }
        
        std::cout << on << "/" << od << "\n";
    }
    
    return 0;
}