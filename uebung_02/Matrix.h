#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>


/*
 * A simple Matrix class for n x m floating point matrices
 */
class Matrix
{
public:
    Matrix( unsigned int n, unsigned int m ); // prepare to use n rows and m columns (memory allocation ....)
    Matrix( const Matrix& m ); // copy constructor
    ~Matrix();	// destructor

    float *operator [] ( unsigned int i ); // index operator to access a row

    const Matrix& operator = ( const Matrix& m ); // assign operator from Matrix m to current matrix (this)

    const Matrix& operator += ( const Matrix& m ); // add m to current matrix element wise
    const Matrix& operator -= ( const Matrix& m ); // subtract m to current matrix element wise
    const Matrix& operator *= ( const Matrix& m ); // matrix-matrix multiplication: this * m
    const Matrix& operator *= ( float s ); // matrix - scalar multiplication: this * s

    void print(); // print matrix to standard output device (usually the console)

    inline unsigned int n(){
        return _n;
    }

    inline unsigned int m(){
        return _m;
    }
//    inline Matrix getMatrix()
//    {
//        return _matrix;
//    }

protected:
    float**_matrix;
    unsigned int _n;
    unsigned int _m;
};

Matrix operator + ( const Matrix& lhs, const Matrix& rhs ); // add the two matrices lhs and rhs and return a new matrix
Matrix operator - ( const Matrix& lhs, const Matrix& rhs ); // subtract the two matrices lhs and rhs and return a new matrix
Matrix operator * ( const Matrix& lhs, const Matrix& rhs ); // multiply the two matrices lhs and rhs and return a new matrix
Matrix operator * ( const Matrix& m, float s ); // multiply the matrix m by the scalar s and return a new matrix

#endif // MATRIX_H
