#pragma once
#include "Gamebryo/NiObjectNET.hpp"

namespace CommonLib {

  class NiProperty : public NiObjectNET
  {
    public:
      NiProperty();
      ~NiProperty();
  };

  static_assert(sizeof(NiProperty) == 0x18, "NiProperty has wrong size");
  
} // namespace CommonLib
