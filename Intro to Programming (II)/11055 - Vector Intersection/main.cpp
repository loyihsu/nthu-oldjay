// Problem: http://140.114.86.238/problem/11055/
#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    std::ios::sync_with_stdio(false);

    std::vector<int> set1, set2, output;
    int eles1, eles2, i, temp;
    
    while (std::cin >> eles1, eles1) {
        output.clear();
        set1.clear();
        set2.clear();

        i = eles1;
        
        while(i--) {
            std::cin >> temp;
            set1.push_back(temp);
        }
        
        std::cin >> eles2;
        i = eles2;
        while(i--) {
            std::cin >> temp;
            set2.push_back(temp);
        }
        
        std::sort(set1.begin(), set1.end());
        std::sort(set2.begin(), set2.end());
        
        std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(output, output.begin()));
        
        if (output.empty()) {
            std::cout << "empty" << std::endl;
        } else {
            auto t = output.begin();
            for (auto o: output) {
                t++;
                std::cout << o;
                if (t != output.end())
                    std::cout << " ";
            }
            std::cout << std::endl;
        }   
    }

    return 0;
}
