#pragma once
#include "Gamebryo/NiPoint3.hpp"

namespace CommonLib {

  class NiMatrix3
  {
    public:
      NiMatrix3();
      ~NiMatrix3();

      NiPoint3 m_pEntry[3];
  };

  static_assert(sizeof(NiMatrix3) == 0x24, "NiMatrix3 has wrong size");
  
} // namespace CommonLib
