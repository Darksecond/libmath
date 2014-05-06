#pragma once

namespace math
{
    /**
     * Convert from degrees to radians
     */
    template<typename T>
    constexpr T to_radians(const T& degrees)
    {
        return degrees * pi<T>()/T(180); 
    }

    /**
     * Convert from radians to degrees
     */
    template<typename T>
    constexpr T to_degrees(const T& radians)
    {
        return radians * T(180)/pi<T>();
    }
}
