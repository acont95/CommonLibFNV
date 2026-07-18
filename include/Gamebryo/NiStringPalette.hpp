#pragma once
#include <cstdint>
#include "Gamebryo/NiProperty.hpp"

namespace CommonLib {

  class NiStringPalette : public NiObject
  {
    public:

      char *m_pcBuffer;
      unsigned int m_uiAllocatedSize;
      unsigned int m_uiEndOfBuffer;
  };

  static_assert(sizeof(NiStringPalette) == 0x14, "NiStringPalette has wrong size");
  
} // namespace CommonLib
