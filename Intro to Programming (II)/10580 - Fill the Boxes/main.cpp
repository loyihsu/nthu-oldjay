// Problem: http://140.114.86.238/problem/10580/
#include <iostream>
#include <vector>

int main(void)
{
    long long size, temp;
    std::vector<long long> e;
    
    while (std::cin >> size)
    {
        long long count = 0, cul = 0;
        e.clear();
        while (std::cin >> temp, temp != 0)
        {
            e.push_back(temp);
        }
        
        for (auto E : e)
        {
            if (E + cul <= size)
            {
                cul += E;
            } else {
                count++;
                cul = E;
            }
        }
        count++;
        
        if (e.empty()) std::cout << 0 << "\n";
        else std::cout << count << "\n";
        
    }
}