#pragma once
#include "Bethesda/BSSimpleArray.hpp"
#include "Bethesda/ParentSpaceNode.hpp"
#include "Bethesda/TeleportLink.hpp"

namespace CommonLib {

  class TeleportPath
  {
    public:
      TeleportPath();
      ~TeleportPath();

      BSSimpleArray<ParentSpaceNode,1024> Spaces;
      BSSimpleArray<TeleportLink,1024> Doors;
      NiPoint3 Start;
      NiPoint3 End;
  };

  static_assert(sizeof(TeleportPath) == 0x38, "TeleportPath has wrong size");
  
} // namespace CommonLib
