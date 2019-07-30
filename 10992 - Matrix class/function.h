#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
public:
    Matrix();
    Matrix (const int , const int [50][50]);
    Matrix add(const Matrix) const;//add function
    Matrix subtract(const Matrix) const;//subtract function
    Matrix multiplication(const Matrix) const;//multiply function
    Matrix inc() const;//increased by 1
    void Transpose() const;//Transpose function
    void output() const;//Note that each output should be followed by a new
                        //line character.
private:
    int matrix[50][50];
    int matrix_size;
}; //end class Matrix

#endif /* function_h */
