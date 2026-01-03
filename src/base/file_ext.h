#pragma once

_PHOXO_BEGIN

// image formats.
enum class ImageFormat
{
    Unknown,
    Bmp,
    Jpeg,
    Gif,
    Tiff,
    Png,
    Icon,
    Psd,
    Tga,
    Webp,
    Raw,
    Dds,
    Dng,
    Svg,
    Heif,
    Avif,
    Jxl,
    StbLib,
    Exr,
    OpenJpeg,
};

/// Helper for parsing image file extensions.
class ImageFileExtParser
{
public:
    /// Get file's extension name, not including leading period.
    static CString GetExtName(PCWSTR filepath)
    {
        if (auto p = PathFindExtension(filepath); p && (*p == L'.'))
            return p + 1; // skip '.'
        return L"";
    }

    /// get image format from file path.
    static ImageFormat GetType(PCWSTR filepath)
    {
        using enum ImageFormat;

        CString   e = GetExtName(filepath);
        e.MakeLower();

        // ---- JPEG ----
        if (e == L"jpg" || e == L"jpeg" || e == L"jpe")
            return Jpeg;

        // ---- common formats ----
        if (e == L"png") return Png;
        if (e == L"bmp") return Bmp;
        if (e == L"gif") return Gif;
        if (e == L"ico") return Icon;
        if (e == L"psd") return Psd;
        if (e == L"tga") return Tga;
        if (e == L"webp") return Webp;
        if (e == L"dds") return Dds;
        if (e == L"dng") return Dng;
        if (e == L"svg") return Svg;
        if (e == L"avif") return Avif;
        if (e == L"jxl") return Jxl;
        if (e == L"exr") return Exr;

        // ---- TIFF ----
        if (e == L"tiff" || e == L"tif")
            return Tiff;

        // ---- HEIF ----
        if (e == L"heif" || e == L"heic")
            return Heif;

        // ---- RAW GROUP ----
        if (IsRawExt(e))
            return Raw;

        // ---- STB GROUP ----
        if (e == L"hdr" || e == L"ppm" || e == L"pgm")
            return StbLib;

        // ---- OPENJPEG ----
        if (e == L"j2k" || e == L"jp2")
            return OpenJpeg;

        return Unknown;
    }

public:
    static constexpr PCWSTR   ExtJpeg = L",jpg,jpeg,jpe,";
    static constexpr PCWSTR   ExtRaw = L",arw,cr2,cr3,nef,orf,raf,rw2,dng,";

private:
    static bool IsRawExt(const CString& e)
    {
        return
            e == L"arw" || e == L"cr2" || e == L"cr3" ||
            e == L"nef" || e == L"orf" || e == L"raf" ||
            e == L"rw2" || e == L"dng";
    }
};

_PHOXO_NAMESPACE_END
