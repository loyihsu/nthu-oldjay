// Problem: http://140.114.86.238/problem/10477/
#include <iostream>
#include <algorithm>

int arr[105];
std::string input;
char output[105];
int k;

void find(int cur, int pos)
{
    if (cur == k)
    {
        output[cur] = '\0';
        std::cout << output << "\n";
        return;
    } else {
        for (int i = pos; i < input.size(); i+=arr[i])
        {
            output[cur] = input.at(i);
            find(cur+1, i+1);
        }
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    
    int tcs, j, count;
    char last;
    auto app = [&count, &j]()->void
    {
        while (count >= 1)
            arr[j++] = count--;
    };
    
    std::cin >> tcs;
    
    while (tcs--)
    {
        j = 0;
        count = 0;
        input.clear();
        std::cin >> input >> k;
        std::sort(input.begin(), input.end());
        last = input.at(0);
        
        for (auto k: input)
        {
            if (k == last)
                count++;
            else {
                app();
                count = 1;
                last = k;
            }
        }
        app();
        
        find(0,0);
        std::cout << "\n";
    }
    return 0;
}