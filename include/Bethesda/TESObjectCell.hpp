#pragma once
#include <cstdint>
#include "Bethesda/TESForm.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/ExtraDataList.hpp"
#include "Bethesda/TESObjectLAND.hpp"
#include "Bethesda/TESTexture.hpp"
#include "Bethesda/TESObjectREFR.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiTMap.hpp"

class TESObjectCELL : TESForm, TESFullName
{
  public:
    TESObjectCELL();
    ~TESObjectCELL();

    struct EXTERIOR_DATA
    {
      int iCellX;
      int iCellY;
      char cLandHideFlags;
    };

    struct INTERIOR_DATA
    {
      unsigned int iAmbient;
      unsigned int iDirectional;
      unsigned int iFog;
      float fFogNear;
      float fFogFar;
      unsigned int iDirectionalXY;
      unsigned int iDirectionalZ;
      float fDirectionalFade;
      float fClipDist;
      float fFogPower;
      unsigned int iInteriorOffset;
    };

    struct LOADED_CELL_DATA
    {
      NiPointer<NiNode> spCell3D;
      BSSimpleList<TESObjectREFR *> LargeAnimatedRefs;
      NiTMap<TESObjectREFR *,NiNode *> AnimatedRefMap;
      NiTMap<TESForm *,TESObjectREFR *> EmittanceSourceRefMap;
      NiTMap<TESObjectREFR *,NiNode *> EmittanceLightRefMap;
      NiTMap<TESObjectREFR *,NiPointer<BSMultiBoundNode> > MultiboundRefMap;
      BSSimpleList<TESObjectREFR *> ScriptedRefs;
      BSSimpleList<TESObjectREFR *> ActivatingRefs;
      BSSimpleList<TESObjectREFR *> WaterRefs;
    };

    union CellData
    {
      void* pCellData;
      EXTERIOR_DATA *pCellDataExterior;
      INTERIOR_DATA *pCellDataInterior;
    };

    union WorldData
    {
      TESWorldSpace* pWorldSpace;
      unsigned int iTempDataOffset;
    };

    std::uint8_t cCellFlags;
    std::uint8_t cCellGameFlags;
    std::uint8_t cCellState;
    ExtraDataList ExtraData;
    CellData cCellData;
    TESObjectLAND *pCellLand;
    float fWaterHeight;
    bool bAutoWaterLoaded;
    TESTexture WaterNoiseTexture;
    NavMeshArray *pNavMeshes;
    BSSpinLock kSpinLock;
    int iCriticalQueuedRefCount;
    int iQueuedRefCount;
    std::int16_t sNumRefsWithVisibleDistant;
    std::int16_t sNumLoadedRefsWithVisibleDistant;
    BSSimpleList<TESObjectREFR *> listReferences;
    NiPointer<NiNode> spLightMarkerNode;
    NiPointer<NiNode> spSoundMarkerNode;
    NiPointer<NiNode> spMultiBoundNode;
    WorldData wWorldData;
    LOADED_CELL_DATA *pLoadedData;
    float fLodFadeInPercent;
    bool bLODFadingIn;
    bool bFadedIn;
    bool bFadingToHighDetail;
    bool bFadingToLowDetail;
    bool bDisplayHighDetail;
    bool bCellDetached;
    bool bUpdateTerrain;
    NiPointer<BSPortalGraph> spPortalGraph;
    BGSLightingTemplate *pLightingTemplate;
    unsigned int iLightingTemplateInheritanceFlags;
};
