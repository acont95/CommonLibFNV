#pragma once
#include "Gamebryo/NiObject.hpp"

namespace CommonLib {

  class TESObjectCELL;

  class BSTempEffect : public NiObject
  {
    public:

      float fLifetime;
      TESObjectCELL* pCell;
      float fAge;
      bool bInitialized;
  };

  static_assert(sizeof(BSTempEffect) == 0x18, "BSTempEffect has wrong size");
  
} // namespace CommonLib
