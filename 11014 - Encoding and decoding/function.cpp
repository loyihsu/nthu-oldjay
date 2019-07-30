// Problem: http://140.114.86.238/problem/11014
#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "function.h"

void RleCodec::encode() {
    std::string output;
    int num = 0, i;
    char last;
    
    auto append = [&]() -> void {
        if (num <= 2) {
            for (i = 0; i < num; i++)
                output.push_back(last);
        } else {
            output += std::to_string(num) + last;
        }
    };
    
    if (!code_str.empty()) {
        last = code_str[0];
        for (auto c : code_str) {
            if (c == last) {
                num++;
            } else {
                append();
                num = 1;
                last = c;
            }
        }
        append();
    }
    
    code_str = output;
    encoded = true;
}

void RleCodec::decode() {
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
