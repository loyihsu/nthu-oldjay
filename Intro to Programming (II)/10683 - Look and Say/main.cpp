// Problem: http://140.114.86.238/problem/10683/
#include <cstdio>
#include <iostream>
#include <string>

int main(void)
{
    std::ios::sync_with_stdio(false);

    int l, times;
    std::cin >> l;
    std::string num;
    std::string output;
    char last;
    int count;
    
    auto append = [&output, &count, &last]() ->void {
        output += std::to_string(count);
        output += last;
    };
    
    while (l--)
    {
        std::cin >> num;
        std::cin >> times;
        
        output.clear();
        
        while (times--)
        {
            if (!output.empty())
                num = output;
            output.clear();
            last = num.at(0);
            count = 0;
            for (auto n : num)
            {
                if (last == n)
                {
                    count++;
                } else {
                    append();
                    last = n;
                    count = 1;
                }
            }
            append();
            if (times == 0)
                std::cout << output << std::endl;
        }
    }
    return 0;
}