#include <iostream>
#include <stdio.h>
#include "function.h"
using namespace std;

int main(){
    int matrixsize;
    int matrix1[50][50];

    cin >> matrixsize;
    for (int i = 0; i<matrixsize; i++) {
        for (int j = 0; j<matrixsize; j++) {
            cin >> matrix1[i][j];
        }
    }

    int s1, s2;
    cin >> s1 >> s2;

    Matrix a(matrixsize, matrix1);
    Matrix ans;

    ans = a.row(s1,s2);
    ans.output();
    cout << endl;

    ans = a.rotate90();
    ans.output();
    cout << endl;

    ans = a.rotatecounter90();
    ans.output();
    cout << endl;

    a.symmetric();

} // end main

