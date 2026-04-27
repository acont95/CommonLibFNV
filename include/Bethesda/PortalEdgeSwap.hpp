#pragma once
#include "Bethesda/NavMeshEdgeHandle.hpp"

namespace CommonLib {

  class PortalEdgeSwap
  {
    public:

      NavMeshEdgeHandle hOldEdge;
      NavMeshEdgeHandle hNewEdge;
      bool bFromAddition;
  };

  static_assert(sizeof(PortalEdgeSwap) == 0x1C, "PortalEdgeSwap has wrong size");
  
} // namespace CommonLib
