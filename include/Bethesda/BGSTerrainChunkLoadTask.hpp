#pragma once
#include "Bethesda/QueuedFileEntry.hpp"
#include "BGSTerrainChunk.hpp"

class BGSTerrainChunkLoadTask : public QueuedFileEntry
{
  public:
    BGSTerrainChunkLoadTask();
    virtual ~BGSTerrainChunkLoadTask();
  
    bool bFinishedQueuing;
    int iX;
    int iY;
    int iLevel;
    BGSTerrainChunk *pChunk;
    TESWorldSpace *pWorldSpace;
    NiPointer<NiGeometry> spMesh;
    NiPointer<NiGeometry> spWater;
    NiPointer<NiGeometry> spWaterAtReflectionHeight;
    NiPointer<BSMultiBoundNode> spNode;
    bool bCanceled;
};

static_assert(sizeof(BGSTerrainChunkLoadTask) == 0x60, "BGSTerrainChunkLoadTask has wrong size");
