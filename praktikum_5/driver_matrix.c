#include <stdio.h>
#include "matrix.h"
#include "boolean.h"
int main()
{
    Matrix m;
    CreateMatrix(4, 4, &m);
    readMatrix(&m, 4, 4);
    printf("%f", determinant(m));
    return 0;
}