#ifndef MATRIX_HPP
#define MATRIX_HPP


class Matrix
{

public:
    Matrix();
    Matrix (const int , const int[50][50]);
    Matrix row( const int, const int) const;
    Matrix rotate90() const;
    Matrix rotatecounter90() const;
    void symmetric() const;
    void output() const;

private:
    int matrix[50][50];
    int matrix_size;
}; //end class Matrix

#endif
