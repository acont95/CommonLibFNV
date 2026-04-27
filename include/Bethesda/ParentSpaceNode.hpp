#pragma once

namespace CommonLib {

  class TESWorldSpace;
  class TESObjectCELL;

  class ParentSpaceNode
  {
    public:

      bool bWorldSpace;
      TESWorldSpace *pWorldSpace;
      TESObjectCELL *pInteriorCell;
  };

  static_assert(sizeof(ParentSpaceNode) == 0xC, "ParentSpaceNode has wrong size");
  
} // namespace CommonLib
