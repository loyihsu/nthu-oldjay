// Problem: http://140.114.86.238/problem/11014
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "function.h"

void RleCodec::encode()
{
    int num = 0;
    char last;
    std::string os;
    auto append = [&]() -> void
    {
        if (num <= 2)
        {
            for (int i = 0; i < num; i++)
                os.push_back(last);
        } else {
            os += std::to_string(num) + last;
        }
    };
    
    if (!code_str.empty())
    {
        last = code_str.at(0);
        for (auto c: code_str)
        {
            if (c == last)
                num++;
            else {
                append();
                last = c;
                num = 1;
            }
        }
        append();
    }
    
    code_str = os;
    encoded = true;
}

void RleCodec::decode()
{
    std::stringstream os;
    std::string int_str;
    for (auto c : code_str) {
        if (std::isdigit(c)) {
            int_str.push_back(c);
        } else {
            int cnt = 0;
            std::stringstream is{int_str};
            is >> cnt;
            if (cnt==0) {
                os << c;
            } else {
                for (int i=0; i<cnt; ++i)
                    os << c;
            }
            int_str.clear();
        }
    }
    
    code_str = os.str();
    encoded = false;
}


