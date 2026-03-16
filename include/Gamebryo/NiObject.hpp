#pragma once
#include "Gamebryo/NiRefObject.hpp"

namespace CommonLib {

  class NiObject : public NiRefObject 
  {
    public:
      NiObject();
      ~NiObject();
  };

  static_assert(sizeof(NiObject) == 0x8, "NiObject has wrong size");
  
} // namespace CommonLib
