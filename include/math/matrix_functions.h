#pragma once

namespace math
{
    /**
     * Calculate a projection matrix from a set of parameters.
     * \param fov field of view, in radians.
     */
    template<typename T>
    matrix<T, 4, 4> perspective(const T fovy, const T aspect, const T near, const T far)
    {
        assert(aspect != T(0));
        assert(near != far);

        const T y = tan(fovy / T(2));

        matrix<T, 4, 4> result;
        result[0][0] = T(1) / (aspect * y);
        result[1][1] = T(1) / y;
        result[2][2] = - (far + near) / (far - near);
        result[2][3] = - (T(2) * far * near) / (far - near);
        result[3][2] = - T(1);
        return result;
    }
}
