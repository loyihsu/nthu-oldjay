// Problem: http://140.114.86.238/problem/11834/
#include <iostream>
using namespace std;
void hanoi(int n, char A, char B, char C);

int main(){
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}