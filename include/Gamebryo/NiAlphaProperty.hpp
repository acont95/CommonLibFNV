#pragma once
#include <cstdint>

namespace CommonLib {

  class NiAlphaProperty
  {
    public:
      NiAlphaProperty();
      ~NiAlphaProperty();

      enum AlphaFunction
      {
        ALPHA_ONE = 0x0,
        ALPHA_ZERO = 0x1,
        ALPHA_SRCCOLOR = 0x2,
        ALPHA_INVSRCCOLOR = 0x3,
        ALPHA_DESTCOLOR = 0x4,
        ALPHA_INVDESTCOLOR = 0x5,
        ALPHA_SRCALPHA = 0x6,
        ALPHA_INVSRCALPHA = 0x7,
        ALPHA_DESTALPHA = 0x8,
        ALPHA_INVDESTALPHA = 0x9,
        ALPHA_SRCALPHASAT = 0xA,
        ALPHA_MAX_MODES = 0xB,
      };

      enum TestFunction
      {
        TEST_MAX_MODES = 0x8,
      };

      std::uint16_t m_uFlags;
      std::uint8_t m_ucAlphaTestRef;
  };

  static_assert(sizeof(NiAlphaProperty) == 0x4, "NiAlphaProperty has wrong size");
  
} // namespace CommonLib
