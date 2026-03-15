#pragma once
#include <cstdint>
#include "Bethesda/TESWorldSpace.hpp"
#include "Bethesda/BGSTerrainNode.hpp"
#include "Bethesda/BSSimpleArray.hpp"
#include "Bethesda/TESObjectREFR.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiNode.hpp"

class BGSTerrainManager
{
  public:
    BGSTerrainManager();
    ~BGSTerrainManager();

    TESWorldSpace* pWorld;
    BGSTerrainNode* pRootNode;
    NiPointer<NiNode> spLODRoot;
    NiPointer<NiNode> spLODWaterRoot;
    std::int16_t sMinCellX;
    std::int16_t sMinCellY;
    std::int16_t sMaxCellX;
    std::int16_t sMaxCellY;
    unsigned int iMaxLevel;
    unsigned int iMinLevel;
    unsigned int iRootLevel;
    unsigned int iBlockLevel;
    bool bNeedsImmediateUpdate;
    bool bHasLOD;
    BSSimpleArray<TESObjectREFR *,1024> TreesQueuedToHide;
};

static_assert(sizeof(BGSTerrainManager) == 0x3C, "BGSTerrainManager has wrong size");
