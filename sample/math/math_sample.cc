#include <cstdio>
#include <cassert>
#include <math/math.h>

int main()
{
    math::mat4x4 projection = math::perspective(math::to_radians(75.0f), 4.0f/3.0f, 0.01f, 100.0f);
    math::vec4 a(1,2,3,4);
    math::vec4 b = projection * a;
    printf("[%f, %f, %f, %f]\n", b.x, b.y, b.z, b.w);

    //math::mat3x2 a(1,2,3,4,5,6);
    //math::mat2x3 b = transpose(a);
    //printf("[%f, %f, %f]\n", b[0][0], b[0][1], b[0][2]);
    //printf("[%f, %f, %f]\n", b[1][0], b[1][1], b[1][2]);

    //math::mat2x2 c(1,2,3,4);
    //printf("[%f, %f]\n", c[0][0], c[0][1]);
    //printf("[%f, %f]\n", c[1][0], c[1][1]);

    //math::mat2x3 a;
    //math::vec3 b;
    //math::mat3x3 c(a, b);

    //math::mat3x2 d;
    //math::vec3 e;
    //math::mat3x3 f(d, e);

    //math::mat2x2 c;
    //printf("[%f, %f]\n", c[0][0], c[0][1]);
    //printf("[%f, %f]\n", c[1][0], c[1][1]);

    //math::mat2x2 c = math::mat2x2::identity();
    //printf("[%f, %f]\n", c[0][0], c[0][1]);
    //printf("[%f, %f]\n", c[1][0], c[1][1]);

    //math::mat2x3 a;
    //a[0][0] = 0;
    //a[0][1] = 3;
    //a[0][2] = 5;
    //a[1][0] = 5;
    //a[1][1] = 5;
    //a[1][2] = 2;

    //math::vec3 b(3, 4, 3);

    //math::vec2 c = a * b; // M*v
    //printf("[%f, %f]\n", c.x, c.y);
    //printf("should be [27, 41]\n");
    
    //math::mat3x3 a;
    //a[0][0] = 2;
    //a[0][1] = 1;
    //a[0][2] = 3;
    //a[1][0] = 3;
    //a[1][1] = 3;
    //a[1][2] = 2;
    //a[2][0] = 4;
    //a[2][1] = 1;
    //a[2][2] = 2;

    //math::vec3 b(1, 2, 3);

    //math::vec3 c = b * a; //v*M
    //printf("[%f, %f, %f]\n", c.x, c.y, c.z);
    //printf("should be [20, 10, 13]\n");

    return 0;
}
