#pragma once

_PHOXO_BEGIN

/// Helper class.
class SamplingBilinear
{
public:
    /**
     * Returns zero if the coordinate is out of bounds.
     * Only valid within
     *   -1.0 < pt.X < img.Width()
     *   -1.0 < pt.Y < img.Height()
     */
    static Color Get(const Image& img, GPointF pt)
    {
        auto pixel = [&img](POINT pos) -> Color {
            return img.IsInside(pos) ? *(const Color*)img.GetPixel(pos) : Color{}; // 以后需要加clamp
        };

        int   x = Math::Floor(pt.X);
        int   y = Math::Floor(pt.Y);

        return PixelFunc::CalcBilinear(pt.X - x, pt.Y - y,
            pixel({ x, y }),
            pixel({ x + 1, y }),
            pixel({ x, y + 1 }),
            pixel({ x + 1, y + 1 }));
    }
};

_PHOXO_NAMESPACE_END
