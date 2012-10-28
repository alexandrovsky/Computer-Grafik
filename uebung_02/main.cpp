#include "Matrix.h"
#include "Vec3.h"
Matrix *m;
int main(int argc, char** argv)
{
    m = new Matrix(5,5);
    m->print();

    // unit test

    return 0;
}

