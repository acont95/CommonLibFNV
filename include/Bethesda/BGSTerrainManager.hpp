#pragma once
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
    __int16 sMinCellX;
    __int16 sMinCellY;
    __int16 sMaxCellX;
    __int16 sMaxCellY;
    unsigned int iMaxLevel;
    unsigned int iMinLevel;
    unsigned int iRootLevel;
    unsigned int iBlockLevel;
    bool bNeedsImmediateUpdate;
    bool bHasLOD;
    BSSimpleArray<TESObjectREFR *,1024> TreesQueuedToHide;
};

static_assert(sizeof(BGSTerrainManager) == 0x3C, "BGSTerrainManager has wrong size");
