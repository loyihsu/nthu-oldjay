// Problem: http://140.114.86.238/problem/10992
#include "function.h"
#include <iostream>

Matrix::Matrix()
{
    int mat[50][50];
    int i, j;
    for (i = 0; i<50; i++)
    {
        for (j = 0; j < 50; j++)
        {
            mat[i][j] = 0;
        }
    }
    
    Matrix(0, mat);
}

Matrix::Matrix (const int a , const int b[50][50])
{
    int i, j;
    matrix_size = a;
    
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            matrix[i][j] = b[i][j];
        }
    }
    return;
}

Matrix Matrix::add(const Matrix b) const
{
    int i, j;
    Matrix answer;
    
    for (i = 0; i < matrix_size; i++)
    {
        for (j = 0; j< matrix_size; j++)
        {
            answer.matrix[i][j] = matrix[i][j] + b.matrix[i][j];
        }
    }
    
    answer.matrix_size = matrix_size;
    
    return answer;
}

Matrix Matrix::subtract(const Matrix b) const
{
    int i, j;
    Matrix answer;
    
    for (i = 0; i < matrix_size; i++)
    {
        for (j = 0; j< matrix_size; j++)
        {
            answer.matrix[i][j] = matrix[i][j] - b.matrix[i][j];
        }
    }
    
    answer.matrix_size = matrix_size;
    
    return answer;
}

Matrix Matrix::multiplication(const Matrix b) const
{
    int i, j, k;
    Matrix answer;
    
    for (i = 0; i < matrix_size; i++)
    {
        for (j = 0; j< matrix_size; j++)
        {
            for (k = 0; k < matrix_size; k++)
                answer.matrix[i][j] = 0;
        }
    }
    
    
    for (i = 0; i < matrix_size; i++)
    {
        for (j = 0; j< matrix_size; j++)
        {
            for (k = 0; k < matrix_size; k++)
                answer.matrix[i][j] += matrix[i][k] * b.matrix[k][j];
        }
    }
    
    answer.matrix_size = matrix_size;
    
    return answer;
}

Matrix Matrix::inc() const
{
    int i, j;
    Matrix answer;
    
    for (i = 0; i < matrix_size; i++)
    {
        for (j = 0; j< matrix_size; j++)
        {
            answer.matrix[i][j] = matrix[i][j] + 1;
            if (answer.matrix[i][j] >= 10)
                answer.matrix[i][j] %= 10;
        }
    }
    
    answer.matrix_size = matrix_size;
    
    return answer;
}

void Matrix::Transpose() const
{
    int i, j;
    for (i = 0; i < matrix_size; i++)
    {
        for (j = 0; j < matrix_size; j++)
        {
            std::cout << matrix[j][i];
            if (j != matrix_size -1)
                std::cout << " ";
        }
        std::cout << "\n";
    }
}

void Matrix::output() const
{
    int i, j;
    for (i = 0; i < matrix_size; i++)
    {
        for (j = 0; j < matrix_size; j++)
        {
            std::cout << matrix[i][j];
            if (j != matrix_size -1)
                std::cout << " ";
        }
        std::cout << "\n";
    }
}
