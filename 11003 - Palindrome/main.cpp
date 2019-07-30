#include <iostream>
#include <cstring>
#include "function.h"

using namespace std;

int main() {
    char input[100001];
    
    while(cin >> input) {
    	SimpleString s(input, strlen(input));
        PalindromeChecker c(s);
        c.isPalindrome();
    }

    return 0;
}
