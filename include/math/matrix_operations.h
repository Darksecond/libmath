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
            result[m] *= T(a);
        }
        return result;
    }

    /**
     * Matrix-scalar division
     */
    template<typename T, int N, int M, typename Y>
    matrix<T, N, M> operator/(const matrix<T, N, M>& a, const Y& b)
    {
        matrix<T, M, N> result(a);
        for(int n=0;n<N;++n)
        {
            result[n] /= T(b);
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

    /**
     * Transpose a matrix.
     */
    template<typename T, int N, int M>
    matrix<T, M, N> transpose(const matrix<T, N, M>& a)
    {
        matrix<T, M, N> result;
        for(int n=0;n<N;++n)
            for(int m=0;m<M;++m)
                result[m][n] = a[n][m];
        return result;
    }

    /**
     * calculate the minor matrix of matrix a.
     * A minor matrix is a matrix with one column and one row removed (so the minor of a 3x3 would be a 2x2)
     * i and j are zero based (zero is first row/column)
     */
    template<typename T, int N, int M>
    matrix<T, N-1, M-1> minor(const matrix<T, N, M>& a, int i, int j)
    {
        matrix<T, N-1, M-1> result;
        for(int n=0;n<N-1;++n)
        {
            for(int m=0;m<M-1;++m)
            {
                result[n][m] = a[n+(n>=i)][m+(m>=j)];
            }
        }
        return result;
    }

    template<typename T, int N>
    T determinant(const matrix<T, N, N>& a);

    /**
     * Calculate the determinant for a 1x1 matrix.
     */
    template<typename T>
    T determinant(const matrix<T, 1, 1>& a)
    {
        return a[0][0];
    }

    /**
     * Calculate the determinant for an 2x2 matrix.
     */
    template<typename T>
    T determinant(const matrix<T, 2, 2>& a)
    {
        return a[0][0]*a[1][1] - a[0][1]*a[1][0];
    }

    /**
     * Calculate the determinant for any NxN matrix.
     * This will get exponentially more expensive.
     */
    template<typename T, int N>
    T determinant(const matrix<T, N, N>& a)
    {
        T sum = 0;
        const int i = 0;
        for(int j=0;j<N;++j)
        {
            sum += a[i][j] * ((j & 1) ? -1 : 1) * determinant(minor(a, i, j));
        }
        return sum;
    }

    template<typename T, int N>
    matrix<T, N, N> adjoint(const matrix<T, N, N>& a)
    {
        matrix<T, N, N> result;
        for(int n=0;n<N;++n)
        {
            for(int m=0;m<N;++m)
            {
                result[n][m] = (((n+m) & 1) ? -1 : 1) * determinant(minor(a, m, n));
            }
        }
        return result;
    }

    template<typename T, int N>
    matrix<T, N, N> inverse(const matrix<T, N, N>& a);

    /**
     * Calculate the inverse matrix of a.
     * This is quite heavy on calculations.
     */
    template<typename T, int N>
    matrix<T, N, N> inverse(const matrix<T, N, N>& a)
    {
        return adjoint(a)/determinant(a);
    }

    /**
     * Calculate the inverse of a 1x1 matrix, it's really simple, since it's just a scalar.
     */
    template<typename T>
    matrix<T, 1, 1> inverse(const matrix<T, 1, 1>& a)
    {
        return math::matrix<T, 1, 1>(1/a[0][0]);
    }
}
