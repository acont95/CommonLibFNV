#pragma once
#include <cstdint>
#include "Bethesda/BSMultiBoundShape.hpp"
#include "Gamebryo/NiPointer.hpp"

namespace CommonLib {

  class BSMultiBound : public NiObject
  {
    public:

      std::uint32_t uiBoundFrameCount;
      NiPointer<BSMultiBoundShape> spShape;
  };

  static_assert(sizeof(BSMultiBound) == 0x10, "BSMultiBound has wrong size");
  
} // namespace CommonLib
