// Problem: http://140.114.86.238/problem/10477/
#include <stdio.h>
#include <iostream>
#include <algorithm>

char result[105];
int key[100], k;
std::string str, temp;

void find (int step, int position)
{
    if (step == k)
    {
        result[step] = '\0';
        std::cout << result << "\n";
        return;
    } else {
        for (int b = position; b < str.size(); b += key[b])
        {
            result[step] = str.at(b);
            find(step+1, b+1);
        }
    }
}


int main(void)
{
    std::ios::sync_with_stdio(false);
    
    int i = 0, j = 0, t, count;
    char last;
    
    auto append = [&count, &j]()->void
    {
        while (count >= 1)
        {
            key[j++] = count--;
        }
    };
    
    std::cin >> t;
    
    while (t--)
    {
        str.clear();
        temp.clear();
        
        for (i=0; i < 100; i++)
            key[i] = 0;
        
        std::cin >> str;
        std::cin >> k;
        std::sort(str.begin(), str.end());
        
        last = str.at(0);
        i = 0;
        j = 0;
        count = 0;
        
        for (auto s: str)
        {
            if (s == last)
            {
                count++;
            } else {
                append();
                last = s;
                count = 1;
            }
        }
        append();
        
        find(0, 0);
        std::cout << "\n";
    }
    
    return 0;
}