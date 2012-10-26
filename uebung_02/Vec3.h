#ifndef VEC3_H
#define VEC3_H

#include "Matrix.h"

/*
 * A simple Vector class for 3D floating point vectors
 */
class Vec3 : public Matrix
{
public:
    Vec3(); // constructor, initialized each component with 0
    Vec3( const Vec3& v ); // copy constructor

    float& operator [] ( unsigned int i ); // index operator to access an individual element
    
    float normalize( ); // normalize vector to unit length
};

float operator * ( const Vec3& lhs, const Vec3& rhs ); // scalar multiplication, returns lhs*rhs
Vec3 cross( const Vec3& lhs, const Vec3& rhs ); // cross product, returns lhs x rhs
float norm2( const Vec3& v ) ; // computes length of vector v

#endif // VEC3_H