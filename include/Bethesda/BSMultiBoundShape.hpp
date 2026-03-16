#pragma once
#include <cstdint>
#include "Gamebryo/NiObject.hpp"

namespace CommonLib {

  class BSMultiBoundShape : public NiObject
  {
    public:
      BSMultiBoundShape();
      virtual ~BSMultiBoundShape();

      enum BSMBCullResult
      {
        BS_CULL_UNTESTED = 0x0,
        BS_CULL_VISIBLE = 0x1,
        BS_CULL_CULLED = 0x2,
        BS_CULL_OCCLUDED = 0x3,
      };

      BSMBCullResult kCullResult;
  };

  static_assert(sizeof(BSMultiBoundShape) == 0xC, "BSMultiBoundShape has wrong size");
  
} // namespace CommonLib
