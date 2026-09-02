#pragma once
#include "Gamebryo/NiFixedString.hpp"

namespace CommonLib {

  class NiTextKey
  {
    public:
      float m_fTime;
      NiFixedString m_kText; 
  };

  static_assert(sizeof(NiTextKey) == 0x8, "NiTextKey has wrong size");
  
} // namespace CommonLib
