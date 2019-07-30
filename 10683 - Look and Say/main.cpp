// Problem: http://140.114.86.238/problem/10683/
#include <iostream>
#include <string>

int main(void) {
    int tcs, times, count;
    std::string str, output;
    std::cin >> tcs;
    char last;
    
    auto app = [&output, &count, &last]()->void {
        output += std::to_string(count);
        output += last;
    };
    
    while (tcs--) {
        str.clear();
        output.clear();
        std::cin >> str;
        std::cin >> times;
        while (times--) {
            if (!output.empty()) {
                str = output;
                output.clear();
            }
            
            count = 0;
            last = str.at(0);
            for (auto s: str){
                if (last == s) {
                    count++;
                } else {
                    app();
                    count = 1;
                    last = s;
                }
            }
            app();
        }
        std::cout << output << std::endl;
    }
    
    return 0;
}