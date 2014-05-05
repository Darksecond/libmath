#pragma once

#include <cmath> //for sqrt
#include <math/vector_types.h>

namespace math
{
    /**
     * Do component-wise addition of vectors a and b.
     */
    template<typename T, int N>
    vector<T, N> operator+(const vector<T, N>& a, const vector<T, N>& b)
    {
        vector<T, N> result;
        for(int i=0;i<N;++i)
        {
            result.data[i] = a.data[i] + b.data[i];
        }
        return result;
    }

    /**
     * Do component-wise subtraction of vectors a and b.
     */
    template<typename T, int N>
    vector<T, N> operator-(const vector<T, N>& a, const vector<T, N>& b)
    {
        vector<T, N> result;
        for(int i=0;i<N;++i)
        {
            result.data[i] = a.data[i] - b.data[i];
        }
        return result;
    }

    /**
     * Do component-wise multiplication of vectors a and b.
     */
    template<typename T, int N>
    vector<T, N> operator*(const vector<T, N>& a, const vector<T, N>& b)
    {
        vector<T, N> result;
        for(int i=0;i<N;++i)
        {
            result.data[i] = a.data[i] * b.data[i];
        }
        return result;
    }

    /**
     * Do component-wise division of vectors a and b.
     */
    template<typename T, int N>
    vector<T, N> operator/(const vector<T, N>& a, const vector<T, N>& b)
    {
        vector<T, N> result;
        for(int i=0;i<N;++i)
        {
            result.data[i] = a.data[i] / b.data[i];
        }
        return result;
    }

    /**
     * Negate vector a.
     */
    template<typename T, int N>
    vector<T, N> operator-(const vector<T, N>& a)
    {
        vector<T, N> result;
        for(int i=0;i<N;++i)
        {
            result.data[i] = -a.data[i];
        }
        return result;
    }

    /**
     * Do component-wise multiplication between vector a and scalar b.
     */
    template<typename T, int N, typename Y>
    vector<T, N> operator*(const vector<T, N>& a, const Y& b)
    {
        const T value(b);

        vector<T, N> result;
        for(int i=0;i<N;++i)
        {
            result.data[i] = a.data[i] * value;
        }
        return result;
    }

    template<typename T, int N, typename Y>
    vector<T, N> operator*(const Y& b, const vector<T, N>& a)
    {
        return a * b;
    }

    template<typename T, int N, typename Y>
    vector<T, N> operator*=(vector<T, N>& a, const Y& b)
    {
        const T value(b);

        for(int i=0;i<N;++i)
        {
            a.data[i] *= value;
        }
        return a;
    }

    template<typename T, int N, typename Y>
    vector<T, N> operator/=(vector<T, N>& a, const Y& b)
    {
        const T value(b);
        for(int i=0;i<N;++i)
        {
            a.data[i] /= value;
        }
        return a;
    }

    /**
     * Sum all elements in vector a together.
     */
    template<typename T, int N>
    T sum(const vector<T, N>& a)
    {
        T result = a.data[0];
        for(int i=1;i<N;++i)
        {
            result += a.data[i];
        }
        return result;
    }

    /**
     * Calculate the dot product for vector a and b.
     */
    template<typename T, int N>
    T dot(const vector<T, N>& a, const vector<T, N>& b)
    {
        return sum(a*b);
    }

    /**
     * Calculate the cross product for vector a and b.
     * Vector a and b _must_ be of size 3.
     */
    template<typename T>
    vector<T, 3> cross(const vector<T, 3>& a, const vector<T, 3>& b)
    {
        return vector<T, 3>(
                a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x);
    }

    /**
     * Calculate the length of vector a.
     * TODO: Return value always a float/double? (right now it will return integers for ivecs)
     */
    template<typename T, int N>
    T length(const vector<T, N>& a)
    {
        return sqrt(dot(a, a));
    }

    /**
     * Normalize vector a.
     * TODO: This will always return a vector with only zeroes for integer vectors.
     */
    template<typename T, int N>
    vector<T, N> normalize(const vector<T, N>& a)
    {
        return a * (T(1)/length(a));
    }
}
