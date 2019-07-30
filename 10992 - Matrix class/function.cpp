// Problem: http://140.114.86.238/problem/10992
#include <iostream>
#include <stdio.h>
#include "function.h"

Matrix::Matrix() {
    int i, j;
    
    for(i = 0; i < 50; i++)
        for (j = 0; j < 50; j++)
            matrix[i][j] = 0;
    
    matrix_size = 0;
}

Matrix::Matrix(const int size, const int array[50][50]) {
    int i, j;
    
    for(i = 0; i < 50; i++)
        for (j = 0; j < 50; j++)
            matrix[i][j] = 0;
    
    matrix_size = size;
    
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            matrix[i][j] = array[i][j];
}

Matrix Matrix::add (const Matrix ee) const {
    Matrix output;
    int i, j;
    
    output.matrix_size = matrix_size;
    
    for (i = 0; i < matrix_size; i++)
        for (j = 0; j < matrix_size; j++)
            output.matrix[i][j] = matrix[i][j] + ee.matrix[i][j];
    
    return output;
}

Matrix Matrix::subtract (const Matrix ee) const {
    Matrix output;
    int i, j;
    
    output.matrix_size = matrix_size;
    
    for (i = 0; i < matrix_size; i++)
        for (j = 0; j < matrix_size; j++)
            output.matrix[i][j] = matrix[i][j] - ee.matrix[i][j];
    
    return output;
}

Matrix Matrix::multiplication (const Matrix ee) const {
    Matrix output;
    int i, j, k;
    
    output.matrix_size = matrix_size;
    
    for (i = 0; i < matrix_size; i++)
        for (j = 0; j < matrix_size; j++)
            for (k = 0; k < matrix_size; k++)
                output.matrix[i][k] += matrix[i][j] * ee.matrix[j][k];
    
    return output;
}

Matrix Matrix::inc() const {
    int i, j;
    Matrix output;
    
    for (i = 0; i < matrix_size; i++)
        for (j = 0; j < matrix_size; j++)
            output.matrix[i][j] = (matrix[i][j] + 1) % 10;

    output.matrix_size = matrix_size;
    
    return output;
}

void Matrix::Transpose() const {
    Matrix output;
    int i, j;
    
    for (i = 0; i < matrix_size; i++)
        for (j = 0; j < matrix_size; j++)
            output.matrix[j][i] = matrix[i][j];
    
    for (i = 0; i < matrix_size; i++) {
        for (j = 0; j < matrix_size; j++) {
            std::cout << output.matrix[i][j];
            if (j == matrix_size-1)
                std::cout << "\n";
            else
                std::cout << " ";
        }
    }
}

void Matrix::output() const {
    int i, j;
    
    for (i = 0; i < matrix_size; i++) {
        for (j = 0; j < matrix_size; j++) {
            std::cout << matrix[i][j];
            if (j == matrix_size-1)
                std::cout << "\n";
            else
                std::cout << " ";
        }
    }
}
