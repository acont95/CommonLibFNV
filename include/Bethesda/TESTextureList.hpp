#pragma once
#include <cstdint>

namespace CommonLib {

  class BSFileEntry;

  class TESTextureList 
  {
    public:
      TESTextureList();
      ~TESTextureList();

      std::uint8_t cTextureCount;
      BSFileEntry** pTextureOffsetArray;
  };

  static_assert(sizeof(TESTextureList) == 0x8, "TESTextureList has wrong size");

} // namespace CommonLib
