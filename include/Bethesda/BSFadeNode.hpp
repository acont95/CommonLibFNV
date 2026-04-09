#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleList.hpp"
#include "Gamebryo/NiNode.hpp"

namespace CommonLib {

  class BSNiBoundArray;
  class BSMultiBoundRoom;
  class BSPortal;

  enum ENUM_LOD_MULT : std::int32_t
  {
    LOD_MULT_NONE = 0x0,
    LOD_MULT_OBJECTS = 0x1,
    LOD_MULT_ITEMS = 0x2,
    LOD_MULT_ACTORS = 0x3,
    LOD_MULT_TREES = 0x4,
    LOD_MULT_LANDSCAPE = 0x5,
    LOD_MULT_DISTANTLOD = 0x6,
    LOD_MULT_ACTOR_BODY_PART = 0x7,
    LOD_MULT_RENDEREDMENU = 0x8,
    LOD_MULT_INVISIBLE = 0x9,
    LOD_MULT_DIST_OVERRIDE = 0xA,
    LOD_MULT_TOTAL = 0xB,
  };

  class BSFadeNode : public NiNode
  {
    public:
      BSFadeNode();
      virtual ~BSFadeNode();

      float fNearDistSqr;
      float fFarDistSqr;
      float fLastFade;
      float fCurrentFade;
      float fBoundRadius;
      float fTimeSinceUpdate;
      ENUM_LOD_MULT eMultType;
      int iFrameCounter;
      void *pUserData;
      BSNiBoundArray *pBoundArray;
      BSSimpleList<BSMultiBoundRoom*> ParentRoomList;
      BSSimpleList<BSPortal*> ParentPortalList;
  };

  static_assert(sizeof(BSFadeNode) == 0xE4);
  
} // namespace CommonLib
