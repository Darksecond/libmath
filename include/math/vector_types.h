#pragma once

namespace math
{
    template<typename T, int N>
    struct vector
    {
        static_assert(N > 0, "vector must have at least 1 element");

        static constexpr int size = N;
        typedef T type;
        T data[size];

        vector<T, N>()
        {
            for(int i=0;i<N;++i)
            {
                data[i] = 0;
            }
        }

        explicit vector<T, N>(const T value)
        {
            for(int i=0;i<N;++i)
            {
                data[i] = value;
            }
        }

        T& operator[](const int pos) { return data[pos]; }
        constexpr T operator[](const int pos) const { return data[pos]; }
    };

    template<typename T>
    struct vector<T, 2>
    {
        static constexpr int size = 2;
        typedef T type;
        union
        {
            T data[size];
            struct { T x, y; };
        };

        constexpr vector<T, 2>() : x(0), y(0) {}
        explicit constexpr vector<T, 2>(T value) : x(value), y(value) {}
        constexpr vector<T, 2>(T x, T y) : x(x), y(y) {}

        T& operator[](const int pos) { return data[pos]; }
        constexpr T operator[](const int pos) const { return data[pos]; }
    };

    template<typename T>
    struct vector<T, 3>
    {
        static constexpr int size = 3;
        typedef T type;
        union
        {
            T data[size];
            struct { T x, y, z; };
            struct { T r, g, b; };
            vector<T, 2> xy;
        };

        constexpr vector<T, 3>() : x(0), y(0), z(0) {}
        explicit constexpr vector<T, 3>(T value) : x(value), y(value), z(value) {}
        constexpr vector<T, 3>(T x, T y, T z) : x(x), y(y), z(z) {}

        T& operator[](const int pos) { return data[pos]; }
        constexpr T operator[](const int pos) const { return data[pos]; }
    };

    template<typename T>
    struct vector<T, 4>
    {
        static constexpr int size = 4;
        typedef T type;
        union
        {
            T data[size];
            struct { T x, y, z, w; };
            struct { T r, g, b, a; };
            vector<T, 2> xy;
            vector<T, 3> xyz;
            vector<T, 3> rgb;
        };

        constexpr vector<T, 4>() : x(0), y(0), z(0), w(0) {}
        explicit constexpr vector<T, 4>(T value) : x(value), y(value), z(value), w(value) {}
        constexpr vector<T, 4>(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}
        constexpr vector<T, 4>(vector<T, 3> xyz, T w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}

        T& operator[](const int pos) { return data[pos]; }
        constexpr T operator[](const int pos) const { return data[pos]; }
    };
}
