#pragma once 
#include "Gamebryo/NiObject.hpp"

namespace CommonLib {

  class BSTextureSet : public NiObject
  {
    public:
      BSTextureSet();
      ~BSTextureSet();
  };

  static_assert(sizeof(BSTextureSet) == 0x8, "BSTextureSet has wrong size");
  
} // namespace CommonLib
