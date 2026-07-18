#pragma once
#include <cstdint>
#include "Gamebryo/NiAccumulator.hpp"
#include "Gamebryo/NiTPointerList.hpp"

namespace CommonLib {

  class NiGeometry;

  class NiAVObjectPalette : public NiObject
  {
    public:
      virtual ~NiAVObjectPalette();

  };

  static_assert(sizeof(NiAVObjectPalette) == 0x8, "NiAVObjectPalette has wrong size");
  
} // namespace CommonLib
