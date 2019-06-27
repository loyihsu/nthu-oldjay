// Problem: http://140.114.86.238/problem/10994/
#include <iostream>
#include <stdio.h>
#include "function.h"

Matrix::Matrix()
{
    int i, j;
    matrix_size = 0;
    
    for (i = 0; i < 50; i++)
        for (j = 0; j < 50; j++)
            matrix[i][j] = 0;
}

Matrix::Matrix(const int size, const int array[50][50])
{
    int i, j;
    matrix_size = size;
    
    for (i = 0; i < 50; i++)
        for (j = 0; j < 50; j++)
            matrix[i][j] = 0;
    
    for (i = 0; i < size; i++)
        for (j = 0 ; j < size; j++)
            matrix[i][j] = array[i][j];
}

Matrix Matrix::row( const int a, const int b) const
{
    int i, j;
    Matrix output;
    
    output.matrix_size = matrix_size;
    
    for (i = 0; i < matrix_size; i++)
    {
        for (j = 0; j < matrix_size; j++)
        {
            output.matrix[i][j] = matrix[i][j];
        }
    }
    

    for (j = 0; j < matrix_size; j++)
    {
        output.matrix[a][j] = matrix[b][j];
        output.matrix[b][j] = matrix[a][j];
    }
    
    return output;
}

Matrix Matrix::rotate90() const
{
    int i, j;
    Matrix output;
    
    output.matrix_size = matrix_size;
    
    for (i = 0; i < matrix_size; i++)
        for (j = 0; j < matrix_size; j++)
            output.matrix[i][j] = matrix[matrix_size-1-j][i];
    
    return output;
}

Matrix Matrix::rotatecounter90() const
{
    int i, j;
    Matrix output;
    
    output.matrix_size = matrix_size;
    
    for (i = 0; i < matrix_size; i++)
        for (j = 0; j < matrix_size; j++)
            output.matrix[i][j] = matrix[j][matrix_size-1-i];
    
    return output;
}

void Matrix::symmetric() const
{
    int i, j;
    
    for (i = 0; i < matrix_size; i++)
    {
        for (j = 0; j < matrix_size; j++)
        {
            if (matrix[i][j] != matrix[j][i])
            {
                std::cout << "no" << "\n";
                return;
            }
        }
    }
    std::cout << "yes"<< "\n";
    return;
}

void Matrix::output() const
{
    
    int i, j;
    
    for (i = 0; i < matrix_size; i++)
    {
        for (j = 0; j < matrix_size; j++)
        {
            std::cout << matrix[i][j];
            if (j == matrix_size - 1)
                std::cout << "\n";
            else
                std::cout << " ";
        }
    }

}