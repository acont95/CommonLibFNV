#pragma once
#include "Bethesda/BSSimpleList.hpp"

namespace CommonLib {

  class TESRegionData;
  class TESRegion;

  class TESRegionList : public BSSimpleList<TESRegion *>
  {
    public:
      virtual ~TESRegionList();

      struct CachedData
      {
        TESRegionData *pData;
        TESRegionList *pList;
      };

      bool bOwnsRegionMemory;
  };

  static_assert(sizeof(TESRegionList) == 0x10, "TESRegionList has wrong size");
  
} // namespace CommonLib
