#pragma once
#include "Gamebryo/NiPoint3.hpp"

namespace CommonLib {

  class NavMeshVertex
  {
    public:

      NiPoint3 Location;
  };

  static_assert(sizeof(NavMeshVertex) == 0xC, "NavMeshVertex has wrong size");
  
} // namespace CommonLib
