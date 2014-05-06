#pragma once

#include <math/constants.h>
#include <math/angles.h>

#include <math/vector_types.h>
#include <math/vector_operations.h>

#include <math/matrix_types.h>
#include <math/matrix_operations.h>
#include <math/matrix_functions.h>

namespace math
{
    typedef vector<float, 2> vec2;
    typedef vector<float, 3> vec3;
    typedef vector<float, 4> vec4;

    typedef vector<int, 2> ivec2;
    typedef vector<int, 3> ivec3;
    typedef vector<int, 4> ivec4;

    typedef matrix<float, 2, 2> mat2x2;
    typedef matrix<float, 2, 3> mat2x3;
    typedef matrix<float, 3, 2> mat3x2;
    typedef matrix<float, 3, 3> mat3x3;
    typedef matrix<float, 3, 4> mat3x4;
    typedef matrix<float, 4, 3> mat4x3;
    typedef matrix<float, 4, 4> mat4x4;
}
