// Problem: http://140.114.86.238/problem/11053/
#include <iostream>
#include <set>

int main(void) {
    std::ios::sync_with_stdio(false);
    
    int lines;
    std::string temp;
    std::multiset<std::string> set;

    while (std::cin >> lines, lines) {
        set.clear();
        while (lines--) {
            std::cin >> temp;
            set.insert(temp);
        }
        for (auto s: set)
            std::cout << s << std::endl;

        std::cout << std::endl;
    }
    
    return 0;
}