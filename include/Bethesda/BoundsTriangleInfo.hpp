#pragma once
#include <cstdint>

namespace CommonLib {

  class BoundsTriangleInfo
  {
    public:

      std::uint16_t usTriangleIndex;
      bool bPortals[3];
      std::uint16_t Triangles[3];
  };

  static_assert(sizeof(BoundsTriangleInfo) == 0xC, "BoundsTriangleInfo has wrong size");
  
} // namespace CommonLib
