#pragma once
#include <cstdint>

class NiPixelFormat
{
  public:
    NiPixelFormat();
    ~NiPixelFormat();

    enum Format : std::int32_t
    {
      FORMAT_RGB = 0x0,
      FORMAT_RGBA = 0x1,
      FORMAT_PAL = 0x2,
      FORMAT_PALALPHA = 0x3,
      FORMAT_DXT1 = 0x4,
      FORMAT_DXT3 = 0x5,
      FORMAT_DXT5 = 0x6,
      FORMAT_RGB24NONINTERLEAVED = 0x7,
      FORMAT_BUMP = 0x8,
      FORMAT_BUMPLUMA = 0x9,
      FORMAT_RENDERERSPECIFIC = 0xA,
      FORMAT_ONE_CHANNEL = 0xB,
      FORMAT_TWO_CHANNEL = 0xC,
      FORMAT_THREE_CHANNEL = 0xD,
      FORMAT_FOUR_CHANNEL = 0xE,
      FORMAT_DEPTH_STENCIL = 0xF,
      FORMAT_MAX = 0x11,
    };

    enum Tiling : std::int32_t
    {
      TILE_NONE = 0x0,
      TILE_XENON = 0x1,
      TILE_MAX = 0x2,
    };

    enum Component : std::int32_t
    {
      COMP_RED = 0x0,
      COMP_GREEN = 0x1,
      COMP_BLUE = 0x2,
      COMP_ALPHA = 0x3,
      COMP_COMPRESSED = 0x4,
      COMP_OFFSET_U = 0x5,
      COMP_OFFSET_V = 0x6,
      COMP_OFFSET_W = 0x7,
      COMP_OFFSET_Q = 0x8,
      COMP_LUMA = 0x9,
      COMP_HEIGHT = 0xA,
      COMP_VECTOR_X = 0xB,
      COMP_VECTOR_Y = 0xC,
      COMP_VECTOR_Z = 0xD,
      COMP_PADDING = 0xE,
      COMP_INTENSITY = 0xF,
      COMP_INDEX = 0x10,
      COMP_DEPTH = 0x11,
      COMP_STENCIL = 0x12,
      COMP_EMPTY = 0x13,
      COMP_MAX = 0x14,
      NUM_COMPS = 0x4,
    };

    enum Representation : std::int32_t
    {
      REP_FIXED = 0x0,
      REP_HALF = 0x1,
      REP_FLOAT = 0x2,
      REP_INDEX = 0x3,
      REP_COMPRESSED = 0x4,
      REP_UNKNOWN = 0x5,
      REP_MAX = 0x6,
    };


    struct NiComponentSpec
    {
      Component m_eComponent;
      Representation m_eRepresentation;
      unsigned __int8 m_ucBitsPerComponent;
      bool m_bSigned;
    };


    std::uint8_t m_uFlags;
    std::uint8_t m_ucBitsPerPixel;
    Format m_eFormat;
    Tiling m_eTiling;
    std::uint32_t m_uiRendererHint;
    std::uint32_t m_uiExtraData;
    NiComponentSpec m_akComponents[4];

};

static_assert(sizeof(NiPixelFormat) == 0x44, "NiPixelFormat has wrong size");
