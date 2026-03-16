#pragma once
#include <cstdint>
#include "Bethesda/QueuedFileEntry.hpp"
#include "Bethesda/TESWorldSpace.hpp"
#include "Gamebryo/NiGeometry.hpp"

namespace CommonLib {

  class BGSTerrainChunk;

  class BGSTerrainChunkLoadTask : public QueuedFileEntry
  {
    public:
      BGSTerrainChunkLoadTask();
      virtual ~BGSTerrainChunkLoadTask();
    
      bool bFinishedQueuing;
      std::int32_t iX;
      std::int32_t iY;
      std::int32_t iLevel;
      BGSTerrainChunk *pChunk;
      TESWorldSpace *pWorldSpace;
      NiPointer<NiGeometry> spMesh;
      NiPointer<NiGeometry> spWater;
      NiPointer<NiGeometry> spWaterAtReflectionHeight;
      NiPointer<BSMultiBoundNode> spNode;
      bool bCanceled;
  };

  static_assert(sizeof(BGSTerrainChunkLoadTask) == 0x60, "BGSTerrainChunkLoadTask has wrong size");
  
} // namespace CommonLib
