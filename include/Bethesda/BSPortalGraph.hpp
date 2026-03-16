#pragma once
#include "Bethesda/BSMultiBoundRoom.hpp"

namespace CommonLib {

  class BSOcclusionPlane;
  class BSPortal;
  class BSOcclusionPlane;

  class BSPortalGraph : public NiRefObject
  {
    public:
      BSPortalGraph();
      virtual ~BSPortalGraph();

      NiTPointerList<BSOcclusionPlane *> lOccluderList;
      NiTPointerList<BSPortal *> lPortalList;
      NiTPointerList<NiPointer<BSMultiBoundRoom> > lMultiBoundRoomList;
      NiPointer<BSMultiBoundRoom> spMultiBoundRoomRoot;
      NiTPointerList<NiPointer<BSMultiBoundRoom> > lMultiBoundRoomAccumList;
      NiTObjectArray<NiPointer<NiAVObject> > m_kAlwaysRenderChildren;
      NiPointer<NiNode> spPortalNodeRoot;
      NiTPointerList<NiPointer<NiAVObject> > kAttachAlwaysRenderQueue;
      NiTPointerList<NiPointer<NiAVObject> > kDetachAlwaysRenderQueue;
      BSSimpleArray<NiPointer<NiNode>,1024> kUnboundNodes;
  };

  static_assert(sizeof(BSPortalGraph) == 0x78, "BSPortalGraph has wrong size");
  
} // namespace CommonLib
