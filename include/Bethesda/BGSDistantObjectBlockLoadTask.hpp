#pragma once
#include <cstdint>
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
    std::int32_t iX;
    std::int32_t iY;
    std::int32_t iLevel;
    BGSDistantObjectBlock *pBlock;
    TESWorldSpace *pWorldSpace;
    NiPointer<NiGeometry> spMesh;
    NiPointer<BSMultiBoundNode> spNode;
    bool bCanceled;
    bool bStingerVersion;
};

static_assert(sizeof(BGSDistantObjectBlockLoadTask) == 0x58, "BGSDistantObjectBlockLoadTask has wrong size");
