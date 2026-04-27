#pragma once
#include <cstdint>
#include "Bethesda/BSDegradePriority.hpp"
#include "Gamebryo/NiObjectNET.hpp"
#include "Gamebryo/NiPixelFormat.hpp"

namespace CommonLib {

  class NiTexture : public NiObjectNET
  {
    public:

      class FormatPrefs
      {
        public:

          enum PixelLayout
          {
            PALETTIZED_8 = 0x0,
            HIGH_COLOR_16 = 0x1,
            TRUE_COLOR_32 = 0x2,
            COMPRESSED = 0x3,
            BUMPMAP = 0x4,
            PALETTIZED_4 = 0x5,
            PIX_DEFAULT = 0x6,
            SINGLE_COLOR_8 = 0x7,
            SINGLE_COLOR_16 = 0x8,
            SINGLE_COLOR_32 = 0x9,
            DOUBLE_COLOR_32 = 0xA,
            DOUBLE_COLOR_64 = 0xB,
            FLOAT_COLOR_32 = 0xC,
            FLOAT_COLOR_64 = 0xD,
            FLOAT_COLOR_128 = 0xE,
          };

          enum AlphaFormat
          {
            BINARY = 0x1,
            SMOOTH = 0x2,
            ALPHA_DEFAULT = 0x3,
          };

          enum MipFlag
          {
            NO = 0x0,
            YES = 0x1,
            MIP_DEFAULT = 0x2,
          };

          PixelLayout m_ePixelLayout;
          AlphaFormat m_eAlphaFmt;
          MipFlag m_eMipMapped;
      };

      class RendererData : public NiObject
      {
        public:

          NiTexture *m_pkTexture;
          std::uint32_t m_uiWidth;
          std::uint32_t m_uiHeight;
          NiPixelFormat m_kPixelFormat;
          BSDegradePriority DegradePriorityRange;
          std::uint8_t cFlags;
      };

      NiTexture::FormatPrefs m_kFormatPrefs;
      NiTexture::RendererData *m_pkRendererData;
      NiTexture *m_pkPrev;
      NiTexture *m_pkNext;

  };

  static_assert(sizeof(NiTexture) == 0x30, "NiTexture has wrong size");
  
} // namespace CommonLib
