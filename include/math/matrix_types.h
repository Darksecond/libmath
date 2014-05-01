#pragma once

namespace math
{
    template<typename T, int Rows, int Cols>
    struct matrix
    {
        static_assert(Cols > 0, "There must be at least one column");
        static_assert(Rows > 0, "There must be at least one row");

        static constexpr int rows = Rows;
        static constexpr int cols = Cols;
        typedef T type;
        typedef vector<T, Cols> row;
        //TODO typedef vector<T, Rows> column; (unused right now)
        row data[Rows];

        row& operator[](const int pos) { return data[pos]; }
        constexpr row operator[](const int pos) const { return data[pos]; }

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
