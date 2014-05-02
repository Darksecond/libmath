#pragma once

#include <math/matrix_types.h>

namespace math
{
    /**
     * matrix-matrix multiplication.
     */
    template<typename T, int M, int N, int P>
    matrix<T, M, P> operator*(const matrix<T, M, N>& a, const matrix<T, N, P>& b)
    {
        matrix<T, M, P> result;
        for(int p=0;p<P;++p)
            for(int m=0;m<M;++m)
                for(int n=0;n<N;++n)
                    result[m][p] += a[m][n] * b[n][p];
        return result;
    }

    /**
     * Matrix-scalar multiplication.
     */
    template<typename T, int M, int N, typename Y>
    matrix<T, M, N> operator*(const Y& a, const matrix<T, M, N>& b)
    {
        matrix<T, M, N> result(b);
        for(int m=0;m<M;++m)
        {
            result[m] *= a;
        }
        return result;
    }

    /**
     * Matrix-scalar multiplication.
     */
    template<typename T, int M, int N, typename Y>
    matrix<T, M, N> operator*(const matrix<T, M, N>& b, const Y& a)
    {
        return a * b;
    }

    /**
     * Matrix-Column vector multiplication
     */
    template<typename T, int N, int M>
    vector<T, N> operator*(const matrix<T, N, M>& a, const vector<T, M>& b)
    {
        vector<T, N> result;
        for(int n=0;n<N;++n)
            for(int m=0;m<M;++m)
                result[n] += a[n][m] * b[m];
        return result;
    }

    /**
     * row vector-matrix multiplication
     */
    template<typename T, int N, int M>
    vector<T,M> operator*(const vector<T, N>& a, const matrix<T, N, M>& b)
    {
        vector<T, M> result;
        for(int n=0;n<N;++n)
            for(int m=0;m<M;++m)
                result[m] += b[n][m] * a[n];
        return result;
    }
}
