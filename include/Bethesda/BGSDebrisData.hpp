#pragma once
#include "Bethesda/TESTextureList.hpp"

namespace CommonLib {

  class BGSDebrisData
  {
    public:
      BGSDebrisData();
      ~BGSDebrisData();

      char cPercentage;
      char cFlags;
      char *pFileName;
      TESTextureList TextureList;
  };

  static_assert(sizeof(BGSDebrisData) == 0x10, "BGSDebrisData has wrong size");
  
} // namespace CommonLib
