#pragma once
#include "Bethesda/BSPortalSharedNode.hpp"
#include "Bethesda/BSOcclusionPlane.hpp"

namespace CommonLib {

  class BSMultiBoundRoom;

  class BSPortal : public BSOcclusionPlane
  {
    public:
      BSPortal();
      virtual ~BSPortal();

      BSMultiBoundRoom *pMultiBoundRoom[2];
      NiPointer<BSPortalSharedNode> spSharedGeometry;
  };

  static_assert(sizeof(BSPortal) == 0x108, "BSPortal has wrong size");
  
} // namespace CommonLib
