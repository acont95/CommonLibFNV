#pragma once
#include "Gamebryo/NiObject.hpp"

namespace CommonLib {

  class hkReferencedObject;

  class bhkRefObject : public NiObject
  {
    public:

      hkReferencedObject *phkObject;
  };

  static_assert(sizeof(bhkRefObject) == 0xC, "bhkRefObject has wrong size");
  
} // namespace CommonLib
