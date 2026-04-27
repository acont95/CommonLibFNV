#pragma once
#include <cstdint>
#include "Bethesda/NavMeshTriHandle.hpp"

namespace CommonLib {

  class NavMeshEdgeHandle : public NavMeshTriHandle
  {
    public:

      std::int32_t iEdgeIndex;
  };

  static_assert(sizeof(NavMeshEdgeHandle) == 0xC, "NavMeshEdgeHandle has wrong size");
  
} // namespace CommonLib
