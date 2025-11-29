#pragma once

_PHOXO_BEGIN

/// Helper
class Math
{
public:
    static BYTE Clamp0255(int n)
    {
        return (BYTE)std::clamp(n, 0, 0xFF);
    }

    static BYTE Clamp0255(const double& d)
    {
        // if d is very large, Clamp0255((int)d) will result in 0 due to integer overflow, we must first clamp to [0,255] before converting.
        return (BYTE)(std::clamp(d, 0.0, 255.0) + 0.5);
    }

    static int CalcStride(int width, int bpp)
    {
        return 4 * ((width * bpp + 31) / 32);
    }

    /// Truncate float/double to int; slightly faster for mostly positive pixel coordinates
    template<typename T>
    static int Floor(T v)
    {
        return (v < 0) ? (int)std::floor(v) : (int)v;
    }
};

_PHOXO_NAMESPACE_END
