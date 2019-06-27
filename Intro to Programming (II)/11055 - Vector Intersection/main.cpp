// Problem: http://140.114.86.238/problem/11055/
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    //freopen("/Users/loyi/ownCloud/CPP/input", "r", stdin);
    
    int ele;
    int i;
    int temp;
    int place;
    
    std::vector<int> output;
    std::vector<int>::iterator t;
    
    while (scanf("%d", &ele), ele != 0)
    {
        i = ele;
        place = 0;
        
        std::vector<int> set1(i);
        
        while (i--)
        {
            scanf("%d", &temp);
            set1.at(place++) = temp;
        }
        
        scanf("%d", &i);
        place = 0;
        std::vector<int> set2(i);
        
        while (i--)
        {
            scanf("%d", &temp);
            set2.at(place++) = temp;
        }
        
        std::sort(set1.begin(), set1.end());
        std::sort(set2.begin(), set2.end());
        
        output.clear();
        t = output.begin();
        
        std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(output, t));
        
        if (output.empty())
            printf("empty");
        else {
            t = output.begin();
            for (auto o:output)
            {
                t++;
                printf("%d", o);
                if (t != output.end())
                    std::cout << " ";
            }
        }
        
        std::cout << "\n";
    }
}


