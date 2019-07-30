// Problem: http://140.114.86.238/problem/10682/
#include <stdio.h>
#include <iostream>
#include <stack>
#include <map>
#include <algorithm>
#include <string>

std::map<char, char> vd = {{'<','>'},{'{','}'},{'(', ')'},{'[', ']'}};

int main(void) {
    std::ios::sync_with_stdio(false);
    std::string tc;
    int cases, i = 0;
    bool valid;
    
    std::cin >> cases;
    getline(std::cin, tc);
    while (i<cases) {
        std::stack<char> S;
        getline(std::cin, tc);
        valid = true;
        for (auto c: tc) {
            if (c == '<' || c == '{' || c == '(' || c == '[') {
                S.push(c);
            } else if (c == '>' || c == '}' || c == ')' || c == ']') {
                if (S.empty()) {
                    valid = false;
                    break;
                } else if (vd[S.top()] != c) {
                    valid = false;
                    break;
                } else {
                    S.pop();
                }
            }
        }
        
        if (!S.empty())
            valid = false;
        
        std::cout << "Case " << i+1 << ": ";
        
        if (valid) std::cout<<"Yes\n";
        else std::cout<<"No\n";
        
        i++;
    }
    
    return 0;
}