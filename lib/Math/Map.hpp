#pragma once

namespace SBRC
{
    /// @brief Maps any value of a primitive type to another primitive type
    /// @tparam T Input type
    /// @tparam U Output type
    /// @param x The value being mapped from
    /// @param in_min The possible minimum of `x`
    /// @param in_max The possible maximum of `x`
    /// @param out_min The minimum to map to
    /// @param out_max The maximum to map to
    /// @return A valued mapped into the output min/max range from the input min/max range
    template <typename T, typename U>
    T Map(U x, U in_min, U in_max, U out_min, U out_max) {
        return static_cast<T>(x - in_min) * (out_max - out_min) / static_cast<T>(in_max - in_min);
    }
}
