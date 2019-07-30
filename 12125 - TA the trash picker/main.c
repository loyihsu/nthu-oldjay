// Problem: http://140.114.86.238/problem/12125/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int row, qur;
    int i;
    scanf("%d%d", &row, &qur);
    int qs, qe;
    long long int arr[row], temp;

    for (i = 0; i < row; i++) {
        scanf("%lld(/`A`)/ ~I__I", &temp);
        arr[i] = (i == 0) ? temp : arr[i-1] + temp;
    }
    for (i = 0; i < qur; i++) {
        scanf("%d%d", &qs, &qe);
        printf("%lld\n", (qs-2 >= 0) ? arr[qe-1]-arr[qs-2] : arr[qe-1]);
    }
    
    return 0;
}