// Problem: http://140.114.86.238/problem/10579/
#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    std::ios::sync_with_stdio(false);

    int testcases, ps, i;
    char temp;
    std::vector<int> set1, set2;
    
    std::cin >> testcases;
    
    while (testcases--) {
        set1.clear();
        set2.clear();
        
        std::cin >> ps;
        i = ps;
        while (i--) {
            std::cin >> temp;
            set1.push_back(temp - '0');
        }
        
        i = ps;
        
        while (i--) {
            std::cin >> temp;
            set2.push_back(temp - '0');
        }
        
        std::reverse(set1.begin(), set1.end());
        std::reverse(set2.begin(), set2.end());
        
        std::vector<int> output;

        output.reserve(ps);
        std::transform(set1.begin(), set1.end(), set2.begin(), std::inserter(output,output.begin()), std::plus<int>());
        
        int up = 0;
        
        for (auto &o: output) {
            o += up;
            up = o / 2;
            o %= 2;
        }
        
        std::reverse(output.begin(), output.end());
        
        for (auto o: output)
            std::cout << o;
        
        std::cout << "\n";
    }
    
    return 0;
}