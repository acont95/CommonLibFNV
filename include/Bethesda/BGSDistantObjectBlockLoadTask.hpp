#pragma once
#include "Bethesda/BGSDistantObjectBlock.hpp"
#include "Bethesda/TESWorldSpace.hpp"
#include "Bethesda/BSMultiBoundNode.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiGeometry.hpp"

class BGSDistantObjectBlockLoadTask : QueuedFileEntry
{
  public:
    BGSDistantObjectBlockLoadTask();
    virtual ~BGSDistantObjectBlockLoadTask();

    bool bFinishedQueuing;
    int iX;
    int iY;
    int iLevel;
    BGSDistantObjectBlock *pBlock;
    TESWorldSpace *pWorldSpace;
    NiPointer<NiGeometry> spMesh;
    NiPointer<BSMultiBoundNode> spNode;
    bool bCanceled;
    bool bStingerVersion;
};

static_assert(sizeof(BGSDistantObjectBlockLoadTask) == 0x58, "BGSDistantObjectBlockLoadTask has wrong size");
