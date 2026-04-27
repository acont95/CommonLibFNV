#pragma once
#include <cstdint>
#include "Bethesda/BGSDistantObjectBlockLoadTask.hpp"

namespace CommonLib {

  class BGSTerrainNode;

  class BGSDistantObjectBlock
  {
    public:

      BGSTerrainNode *pNode;
      NiPointer<NiGeometry> spMesh;
      NiPointer<BSMultiBoundNode> spNode;
      NiPointer<NiGeometry> spOldMesh;
      NiPointer<BSMultiBoundNode> spNodeStinger;
      NiPointer<BSMultiBoundNode> spNodeStingerOld;
      NiPointer<BGSDistantObjectBlockLoadTask> spLoadTask;
      NiPointer<BGSDistantObjectBlockLoadTask> spLoadTaskStinger;
      bool bDoneLoading;
      bool bAttached;
      bool bPrepared;
      bool bHighPriority;
      bool bDetachFlag;
      std::int32_t nDetachCount;
  };

  static_assert(sizeof(BGSDistantObjectBlock) == 0x2C, "BGSDistantObjectBlock has wrong size");
  
} // namespace CommonLib
