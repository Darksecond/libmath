#pragma once

#include <type_traits>
#include <math/vector_types.h>

namespace math
{
    /**
     * This is the layout of a matrix.
     *     M
     *   1 2 3
     * N 4 5 6
     *   7 8 9
     * N == Rows
     * M == Cols
    */
    template<typename T, int Rows, int Cols>
    struct matrix
    {
        static_assert(Cols > 0, "There must be at least one column");
        static_assert(Rows > 0, "There must be at least one row");

        static constexpr int rows = Rows;
        static constexpr int cols = Cols;
        typedef T type;
        typedef vector<T, Cols> row_t; //one row, so a vector Cols long
        typedef vector<T, Rows> column_t; //one column, so a vector Rows long
        union
        {
            T raw[Rows*Cols];
            row_t data[Rows];
        };

        /**
         * Construct a fully zeroed out matrix.
         * This will _not_ create an identity matrix.
         */
        matrix<T, Rows, Cols>()
        {
            for(int i=0;i<Rows*Cols;++i)
                raw[i] = 0;
        }

        /**
         * Create a matrix from a smaller one and a vector.
         * I.e. this will create a 3x3 matrix from a 2x3 matrix and a 3-vector.
         */
        template<int R = Rows, typename std::enable_if<(R > 1)>::type >
        matrix<T, Rows, Cols>(const matrix<T, Rows-1, Cols>& a, const vector<T, Cols>& b)
        {
            for(int r=0;r<Rows-1;++r)
                for(int c=0;c<Cols;++c)
                    data[r][c] = a[r][c];
            for(int c=0;c<Cols;++c)
                data[Rows-1][c] = b[c];
        }

        /**
         * Create a matrix from a smaller one and a vector.
         * I.e. this will create a 3x3 matrix from a 3x2 matrix and a 3-vector.
         */
        template<int C = Cols, typename std::enable_if<(C > 1)>::type >
        matrix<T, Rows, Cols>(const matrix<T, Rows, Cols-1>& a, const vector<T, Rows>& b)
        {
            for(int r=0;r<Rows;++r)
                for(int c=0;c<Cols-1;++c)
                    data[r][c] = a[r][c];
            for(int r=0;r<Rows;++r)
                data[r][Cols-1] = b[r];
        }

        /**
         * construct a matrix with Rows*Cols values of type T (or castable to).
         * the matrix is constructed in the following order: left-to-right, top-to-bottom.
         * TODO safer static_cast (don't allow int->uint for example)
         */
        template<typename... Args>
        matrix<T, Rows, Cols>(Args... args) : raw{static_cast<T>(args)...}
        {
            static_assert(sizeof...(args) == Rows*Cols, "Number of parameters must be N");
        }

	/**
	 * Get row pos.
	 */
        row_t& operator[](const int pos) { return data[pos]; }
        constexpr row_t operator[](const int pos) const { return data[pos]; }

        /**
         * Create an identity matrix.
         * The matrix requested must be square.
         */
        static matrix<T, Rows, Cols> identity()
        {
            static_assert(Rows == Cols, "Matrix must be square");

            matrix<T, Rows, Cols> result;
            for(int m=0;m<Rows;++m)
            {
                result[m][m] = 1;
            }
            return result;
        }
    };
}
