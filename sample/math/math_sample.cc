#include <cstdio>
#include <math/math.h>

int main()
{
    mat2x2 c = mat2x2::identity();
    printf("[%f, %f]\n", c[0][0], c[0][1]);
    printf("[%f, %f]\n", c[1][0], c[1][1]);
    return 0;
}
