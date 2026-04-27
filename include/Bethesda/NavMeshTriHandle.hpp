#pragma once
#include <cstdint>

namespace CommonLib {

  class NavMeshInfo;

  class NavMeshTriHandle
  {
    public:

      NavMeshInfo *pNavMeshInfo;
      std::uint16_t usTriangle;
  };

  static_assert(sizeof(NavMeshTriHandle) == 0x8, "NavMeshTriHandle has wrong size");
  
} // namespace CommonLib
