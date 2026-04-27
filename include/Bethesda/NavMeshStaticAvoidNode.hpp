#pragma once
#include <cstdint>
#include "Bethesda/PathingAvoidNode.hpp"

namespace CommonLib {

  class NavMeshStaticAvoidNode : public PathingAvoidNode
  {
    public:

      std::uint16_t usTriangle;
  };

  static_assert(sizeof(NavMeshStaticAvoidNode) == 0x28, "NavMeshStaticAvoidNode has wrong size");

} // namespace CommonLib
