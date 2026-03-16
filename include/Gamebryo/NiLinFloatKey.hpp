#pragma once
#include "Gamebryo/NiFloatKey.hpp"

namespace CommonLib {

  class NiLinFloatKey : public NiFloatKey
  {
    public:
      NiLinFloatKey();
      ~NiLinFloatKey();
  };

  static_assert(sizeof(NiLinFloatKey) == 0x8, "NiLinFloatKey has wrong size");
  
} // namespace CommonLib
