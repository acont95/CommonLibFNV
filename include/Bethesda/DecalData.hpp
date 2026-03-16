#pragma once
#include <cstdint>

namespace CommonLib {

  class DecalData
  {
    public:
      DecalData();
      ~DecalData();

      struct DECAL_DATA_DATA
      {
        float fDecalMinWidth;
        float fDecalMaxWidth;
        float fDecalMinHeight;
        float fDecalMaxHeight;
        float fDepth;
        float fShininess;
        float fParallaxScale;
        std::uint8_t cParallaxPasses;
        std::uint8_t cFlags;
        std::uint32_t iColor;
      };

      DECAL_DATA_DATA Data;
  };

  static_assert(sizeof(DecalData) == 0x24, "DecalData has wrong size");
    
} // namespace CommonLib
