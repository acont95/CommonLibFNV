#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleArray.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiNode.hpp"

class TESWorldSpace;
class BGSTerrainNode;
class TESObjectREFR;

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
    std::uint32_t iMaxLevel;
    std::uint32_t iMinLevel;
    std::uint32_t iRootLevel;
    std::uint32_t iBlockLevel;
    bool bNeedsImmediateUpdate;
    bool bHasLOD;
    BSSimpleArray<TESObjectREFR *,1024> TreesQueuedToHide;
};

static_assert(sizeof(BGSTerrainManager) == 0x3C, "BGSTerrainManager has wrong size");
