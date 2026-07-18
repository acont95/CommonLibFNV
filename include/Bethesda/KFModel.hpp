#pragma once
#include <cstdint>
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiControllerSequence.hpp"
#include "Bethesda/TESAnimGroup.hpp"

namespace CommonLib {

  class KFModel
  {
    public:
      char *pFilename;
      NiPointer<NiControllerSequence> spSequence;
      NiPointer<TESAnimGroup> spAnimGroup;
      int iRefCount;
      int iManualRefCount;
  };

  static_assert(sizeof(KFModel) == 0x14, "KFModel has wrong size");
  
} // namespace CommonLib
