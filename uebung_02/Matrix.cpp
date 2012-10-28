#include "Matrix.h"


Matrix::Matrix( unsigned int n, unsigned int m ) // prepare to use n rows and m columns (memory allocation ....)
{
    _n = n;
    _m = m;
    _matrix = new float*[_n];
    for(int i = 0; i < _n ; i++){
        _matrix[i] = new float[_m];
    }
}
Matrix::Matrix( const Matrix& m ) // copy constructor
{
    Matrix(m.m(), m.n());
    memcpy(_matrix, m._matrix,sizeof(float)*_m*_n);
}

Matrix::~Matrix()	// destructor
{
    for(int i = 0; i < _n ; i++){
        delete _matrix[i];
    }
    delete _matrix;
}

//float *operator [] ( unsigned int i ); // index operator to access a row
//const Matrix& operator = ( const Matrix& m ); // assign operator from Matrix m to current matrix (this)

const Matrix& Matrix::operator += ( const Matrix& m ) // add m to current matrix element wise
{
    if(m.m() == _m && m.n() == _n)
    {
        float **buffer;
        buffer = m.matrix();
        for(int i = 0; i < _n; i++)
        {
            for(int j = 0; j < _m; j++)
            {
                _matrix[i][j] += buffer[i][j];
            }
        }
        for(int i = 0; i < _n ; i++){
            delete buffer[i];
        }
        delete buffer;
    }
    else
    {
        std::cout << "your matrices are not the same Size" << std::endl;
    }
}

const Matrix& Matrix::operator -= ( const Matrix& m ) // subtract m to current matrix element wise
{
    if(m.m() == _m && m.n() == _n)
    {
        float **buffer;
        buffer = m.matrix();
        for(int i = 0; i < _n; i++)
        {
            for(int j = 0; j < _m; j++)
            {
                _matrix[i][j] -= buffer[i][j];
            }
        }
        for(int i = 0; i < _n ; i++){
            delete buffer[i];
        }
        delete buffer;
    }
    else
    {
        std::cout << "your matrices are not the same Size" << std::endl;
    }
}

//const Matrix& operator *= ( const Matrix& m ); // matrix-matrix multiplication: this * m
//const Matrix& operator *= ( float s ); // matrix - scalar multiplication: this * s

void Matrix::print() // print matrix to standard output device (usually the console)
{
    for(int i = 0; i < _n ; i++){
        for(int j = 0; j < _m ;j++ )
        {
            std::cout << _matrix[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}
