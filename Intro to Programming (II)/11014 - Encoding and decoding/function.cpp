// Problem: http://140.114.86.238/problem/11014
#include "function.h"
#include <iostream>
#include <string>

void RleCodec::encode()
{
    std::string out;
    char last;
    size_t num;
    
    auto append = [&]()->void{
        if (num <= 2)
        {
            for (int i = 0; i < num; i++)
                out.push_back(last);
        } else {
            out += std::to_string(num)+last;
        }
    };
    
    if (!code_str.empty())
    {
        last = code_str[0];
        num = 0;
        for (auto c: code_str)
        {
            if (c == last) num++;
            else {
                append();
                last = c;
                num = 1;
            }
        }
        append();
    }
    
    code_str = out;
    encoded = true;
    
}

void RleCodec::decode()
{
    std::string out;
    char last;
    size_t num = 1;
    
    auto deppend = [&]()->void
    {
        for (int i = 0; i < num; i++)
        {
            out.push_back(last);
        }
    };
    
    for (auto c: code_str)
    {
        if (std::isdigit(c))
        {
            num = c - '0';
        } else {
            last = c;
            deppend();
            num = 1;
        }
    }
    
    code_str = out;
    encoded = false;
}
