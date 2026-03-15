#pragma once
#include <cstdint>
#include "Bethesda/TESForm.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/TESTexture.hpp"
#include "Bethesda/TESObjectCELL.hpp"
#include "Bethesda/TESTerrainLODManager.hpp"
#include "Bethesda/TESClimate.hpp"
#include "Bethesda/BGSTerrainManager.hpp"
#include "Bethesda/TESImageSpace.hpp"
#include "Bethesda/ImpactSwap.hpp"
#include "Bethesda/TESWaterForm.hpp"
#include "Bethesda/BGSEncounterZone.hpp"
#include "Bethesda/BGSMusicType.hpp"

struct WORLD_MAP_DATA
{
  std::uint32_t iUsableWidth;
  std::uint32_t iUsableHeight;
  std::int16_t sNWCellX;
  std::int16_t sNWCellY;
  std::int16_t sSECellX;
  std::int16_t sSECellY;
};

struct WORLD_MAP_OFFSET_DATA
{
  float fMapScale;
  float fMapOffsetX;
  float fMapOffsetY;
};


class TESWorldSpace : TESForm, TESFullName, TESTexture
{
  public:
    TESWorldSpace();
    virtual ~TESWorldSpace();

    enum PARENT_USE_FLAG : std::int32_t
    {
      PU_LAND = 0x0,
      PU_LOD = 0x1,
      PU_MAP = 0x2,
      PU_WATER = 0x3,
      PU_CLIMATE = 0x4,
      PU_IMAGESPACE = 0x5,
      PU_COUNT = 0x6,
    };

    class OFFSET_DATA
    {
      public:
        std::uint32_t *pCellFileOffsets;
        NiPoint2 OffsetMinCoords;
        NiPoint2 OffsetMaxCoords;
        std::uint32_t iFileOffset;
    };

    NiTPointerMap<std::int32_t,TESObjectCELL *> *pCellMap;
    TESObjectCELL *pPersistentCell;
    TESTerrainLODManager TerrainLODManager;
    BGSTerrainManager *pTerrainManager;
    TESClimate *pClimate;
    TESImageSpace *pImageSpace;
    ImpactSwap *pImpactSwap;
    std::uint8_t cFlags;
    std::uint16_t sParentUseFlags;
    NiTPointerMap<std::uint32_t,BSSimpleList<TESObjectREFR *> *> FixedPersistentRefMap;
    BSSimpleList<TESObjectREFR *> MobilePersistentRefList;
    NiTPointerMap<std::uint32_t,BSSimpleList<TESObjectREFR *> *> *pOverlappedMultiboundMap;
    NiPointer<BSPortalGraph> spPortalGraph;
    TESWorldSpace *pParentWorld;
    TESWaterForm *pWorldWater;
    TESWaterForm *pLODWater;
    float fLODWaterHeight;
    WORLD_MAP_DATA WorldMapData;
    WORLD_MAP_OFFSET_DATA WorldMapOffsetData;
    BGSMusicType *pMusicType;
    NiPoint2 MinimumCoords;
    NiPoint2 MaximumCoords;
    NiTMap<TESFile *,TESWorldSpace::OFFSET_DATA *> OffsetDataMap;
    BSStringT<char> cEditorID;
    float fDefaultLandHeight;
    float fDefaultWaterHeight;
    BGSEncounterZone *pEncounterZone;
    TESTexture CanopyShadowTexture;
    TESTexture WaterNoiseTexture;
};

static_assert(sizeof(TESWorldSpace) == 0xEC, "TESWorldSpace has wrong size");
