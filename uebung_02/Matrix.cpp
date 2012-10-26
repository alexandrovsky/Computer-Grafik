#include "Matrix.h"


Matrix::Matrix(unsigned int n, unsigned int m ):_n(n),_m(m)
{
    _matrix = new float*[n];
    for(unsigned int i = 0; i < n; i++)
    {
        _matrix[i] = new float[m];
    }
}

Matrix::Matrix( const Matrix& m )
{
//    this = m;


}

Matrix::~Matrix()
{
    for(unsigned int i = 0; i < _n;i++)
    {
        delete [] _matrix[i];
    }
    delete []_matrix;
}

float *Matrix::operator [] ( unsigned int i ) // index operator to access a row
{
#warning not finished!
    return 0.0;
}
const Matrix& Matrix::operator = ( const Matrix& m ) // assign operator from Matrix m to current matrix (this)
{
    Matrix* tmp = new Matrix(const_cast<unsigned int> (m.n()), const_cast<unsigned int> (m.m()));
    memcpy(tmp->_matrix, m._matrix,sizeof(float)*m.n()*m.m());
    return tmp;
}

const Matrix& Matrix::operator += ( const Matrix& m ) // add m to current matrix element wise
{
    return NULL;
}
const Matrix& Matrix::operator -= ( const Matrix& m ) // subtract m to current matrix element wise
{
    return NULL;
}
const Matrix& Matrix::operator *= ( const Matrix& m ) // matrix-matrix multiplication: this * m
{
    return NULL;
}
const Matrix& Matrix::operator *= ( float s ) // matrix - scalar multiplication: this * s
{
    return NULL;
}

void Matrix::print(){} // print matrix to standard output device (usually the console)
