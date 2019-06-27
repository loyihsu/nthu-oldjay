// Problem: http://140.114.86.238/problem/10580/
#include <stdio.h>
#include <iostream>
#include <vector>

int main(void)
{
    std::ios::sync_with_stdio(false);
    
    long long M;
    std::vector<long long> items;
    long long temp, pls, count, flag = 0;
    
    while (std::cin >> M)
    {
        flag = 0;
        items.clear();
        while (std::cin >> temp, temp != 0)
        {
            flag = 1;
            items.push_back(temp);
        }
        pls = 0;
        count = 0;
        for (auto i : items)
        {
            if (pls + i <= M)
            {
                pls += i;
            }
            else {
                count++;
                pls = i;
            }
        }
        
        count++;
        if (flag == 0) std::cout << 0 << "\n";
        else std::cout << count << "\n";
        
    }
}




