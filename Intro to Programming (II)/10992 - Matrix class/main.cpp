#include <iostream>
#include <stdio.h>
#include "function.h"
using namespace std;

int main(){
    int N;
    int matrix1[50][50], matrix2[50][50];
    Matrix ans;
    
    cin >> N;
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            cin >> matrix1[i][j];
        }
    }
    
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<N; j++) {
            cin >> matrix2[i][j];
        }
    }
    
    Matrix a(N, matrix1), b(N, matrix2);
    
    ans = a.add( b );
    ans.output();
    cout << endl;
    
    ans = a.subtract( b );
    ans.output();
    cout << endl;
    
    ans = a.multiplication( b );
    ans.output();
    cout << endl;
    
    a.inc().output();
    cout << endl;
    b.inc().output();
    cout << endl;
    a.Transpose();
    cout << endl;
    b.Transpose();
    
} // end main

