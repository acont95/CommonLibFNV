#pragma once
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiFixedString.hpp"

namespace CommonLib {

  class NiExtraData : public NiObject {
    public:

      NiFixedString m_kName;
  };

  static_assert(sizeof(NiExtraData) == 0xC, "NiExtraData has wrong size");
  
} // namespace CommonLib
