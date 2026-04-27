#pragma once
#include "Gamebryo/NiBound.hpp"

namespace CommonLib {

  class BSNiBound : public NiBound
  {
    public:

  };

  static_assert(sizeof(BSNiBound) == 0x10, "BSNiBound has wrong size");

} // namespace CommonLib
