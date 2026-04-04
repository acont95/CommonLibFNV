#pragma once
#include <cstdint>
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/ExtraDataList.hpp"
#include "Bethesda/TESTexture.hpp"
#include "Bethesda/BSSpinLock.hpp"
#include "Bethesda/BSMultiBoundNode.hpp"
#include "Bethesda/BSPortalGraph.hpp"
#include "Bethesda/TESForm.hpp"
#include "Gamebryo/NiTMap.hpp"

namespace CommonLib {

  class TESObjectLAND;
  class TESObjectREFR;
  class TESWorldSpace;
  class NavMeshArray;
  class BGSLightingTemplate;

  struct INTERIOR_DATA;

  class TESObjectCELL : public TESForm, public TESFullName
  {
    public:
      TESObjectCELL();
      ~TESObjectCELL();

      struct EXTERIOR_DATA
      {
        std::int32_t iCellX;
        std::int32_t iCellY;
        char cLandHideFlags;
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
        std::uint32_t iTempDataOffset;
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
      std::uint32_t unk68[6];
      BSSpinLock kSpinLock;
      std::int32_t iCriticalQueuedRefCount;
      std::int32_t iQueuedRefCount;
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
      std::uint32_t iLightingTemplateInheritanceFlags;
  };

  static_assert(sizeof(TESObjectCELL) == 0xE0, "TESObjectCELL has wrong size");
  
} // namespace CommonLib
