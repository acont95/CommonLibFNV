#pragma once
#include "Bethesda/BSSimpleList.hpp"
#include "Gamebryo/NiPointer.hpp"

namespace CommonLib {

  class NiNode;
  class NiDirectionalLight;
  class NiFogProperty;
  class GridCellArray;
  class TESObjectCELL;
  class TESRegion;
  class TESWaterSystem;
  class TESWorldSpace;
  class Sky;
  class TESObjectREFR;
  class DeadCountObject;
  class NavMeshInfoMap;
  class NiAVObject;
  class ImageSpaceModifierInstance;
  class QueuedFile;
  class NiSourceTexture;
  class LoadedAreaBound;

  class TES
  {
    public:
      virtual ~TES();
      static TES* GetTESSingleton();

      class ParticleObjectCache
      {
        NiPointer<NiAVObject> spModel;
        NiPointer<NiAVObject> *pspClones;
        TES::ParticleObjectCache *pNext;
      };

      struct GridDistantArray *pGridDistantA;
      GridCellArray *pGridCellA;
      NiNode *pObjRoot;
      NiNode *pObjLandRoot;
      NiNode *pObjLODWaterRoot;
      NiNode *pTempNodeManager;
      NiDirectionalLight *pObjLight;
      NiFogProperty *pObjFog;
      int iCurrentGridX;
      int iCurrentGridY;
      int iCurrentQueuedX;
      int iCurrentQueuedY;
      TESObjectCELL *pInteriorCell;
      TESObjectCELL **pInteriorBuffer;
      TESObjectCELL **pExteriorBuffer;
      unsigned int iTempInteriorBufferSize;
      unsigned int iTempExteriorBufferSize;
      int iSaveGridX;
      int iSaveGridY;
      bool bCollisionBoxes;
      bool bRunningCellTests;
      bool bRunningCellTests2;
      bool bRunningSubmergedObjectTest;
      void (__cdecl *pfnTACCallbackFunc)(TESObjectCELL *, void *);
      void *pTACCallbackData;
      TESRegion *pTACRegionFilter;
      bool bShowLANDborders;
      TESWaterSystem *pWaterSystem;
      Sky *pSky;
      BSSimpleList<NiPointer<ImageSpaceModifierInstance> > listActiveImageSpaceModifiers;
      unsigned int iTotalToLoad;
      unsigned int iLoaded;
      bool bDisablePercentageUpdate;
      bool bUpdateGridString;
      float fCell_delta_x;
      float fCell_delta_y;
      TESWorldSpace *pWorldSpace;
      BSSimpleList<TESObjectCELL *> listLastLoadedExteriors;
      BSSimpleList<TESObjectREFR *> ListofBedsAndChairs;
      BSSimpleList<DeadCountObject *> DeadCount;
      NiPointer<QueuedFile> spPreloadedAddonNodes;
      NiPointer<NiSourceTexture> BloodDecalPreload1;
      NiPointer<QueuedFile> spPreloadedForms;
      TES::ParticleObjectCache *pParticleCacheHead;
      bool bFadeWhenLoading;
      bool bAllowUnusedPurge;
      unsigned int iPlaceableWaterCount;
      NavMeshInfoMap *pNavMeshInfoMap;
      NiPointer<LoadedAreaBound> spLoadedAreaBound;
  };

  static_assert(sizeof(TES) == 0xC4, "TES has wrong size");
  
} // namespace CommonLib
