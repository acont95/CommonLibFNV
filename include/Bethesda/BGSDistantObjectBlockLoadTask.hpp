#pragma once
#include <cstdint>
#include "Bethesda/BSMultiBoundNode.hpp"
#include "Gamebryo/NiGeometry.hpp"
#include "Bethesda/QueuedFileEntry.hpp"

class BGSDistantObjectBlock;
class TESWorldSpace;

class BGSDistantObjectBlockLoadTask : public QueuedFileEntry
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
