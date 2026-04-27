#pragma once
#include "Gamebryo/NiProperty.hpp"

namespace CommonLib {

  class NiPropertyState
  {
    public:

      NiPointer<NiProperty> m_aspProps[7];
  };

  static_assert(sizeof(NiPropertyState) == 0x1C, "NiPropertyState has wrong size");
  
} // namespace CommonLib
