// Problem: http://140.114.86.238/problem/9420/
#include <algorithm>
#include <iostream>
#include <map>

int main(void)
{
    int n;
    int a, b;
    std::map<int, int> edge;
    
    while (std::cin >> n, n != 0)
    {
        edge.clear();
        while (n--)
        {
            std::cin >> a >> b;
            edge[a]++;
            edge[b]++;
        }
        
        std::cin >> a;
        
        std::cout << std::count_if(edge.begin(), edge.end(), [&a](const std::pair<int, int> &v)
        {
            return v.second <= 1 && v.first != a;
        }) << "\n";
    }
    return 0;
}