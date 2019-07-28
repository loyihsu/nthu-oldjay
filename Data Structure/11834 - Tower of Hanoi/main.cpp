// Problem: http://140.114.86.238/problem/11834/
#include <iostream>

void hanoi(int n, char A, char B, char C);

int main() {
    int n;
    
    std::cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}

void hanoi(int n, char A, char B, char C) {
    //move the top disc from A to C
    if (n == 1) {
        std::cout << n << std::endl;
        return;
    }
    //move the top discs from A to B
    hanoi(n-1, A, B, C);
    //move the last disc from A to C
    std::cout << n << std::endl;
    //move the n-1 discs from B to C
    hanoi(n-1, B, C, A);
}
