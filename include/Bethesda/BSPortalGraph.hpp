#pragma once
#include "Bethesda/BSOcclusionPlane.hpp"
#include "Bethesda/BSMultiBoundRoom.hpp"
#include "Bethesda/BSPortal.hpp"
#include "Bethesda/BSSimpleArray.hpp"
#include "Gamebryo/NiTPointerList.hpp"
#include "Gamebryo/NiAVObject.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiNode.hpp"
#include "Gamebryo/NiRefObject.hpp"

class BSPortalGraph : NiRefObject
{
  public:
    BSPortalGraph();
    virtual ~BSPortalGraph();

    NiTPointerList<BSOcclusionPlane *> lOccluderList;
    __unaligned __declspec(align(1)) NiTPointerList<BSPortal *> lPortalList;
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
