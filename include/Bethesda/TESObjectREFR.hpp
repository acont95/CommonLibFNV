#pragma once
#include "Bethesda/TESSound.hpp"
#include "Bethesda/TESBoundObject.hpp"
#include "Bethesda/TESObjectCELL.hpp"
#include "Bethesda/ExtraDataList.hpp"
#include "Bethesda/TESChildCell.hpp"
#include "Bethesda/TESForm.hpp"
#include "Bethesda/bhkPhantom.hpp"
#include "Gamebryo/NiPoint3.hpp"
#include "Gamebryo/NiAVObject.hpp"
#include "Gamebryo/NiPointer.hpp"

class TESObjectREFR : TESForm, TESChildCell
{
  public:
    TESObjectREFR();
    ~TESObjectREFR();

    struct OBJ_REFR
    {
      TESBoundObject* pObjectReference;
      NiPoint3 Angle;
      NiPoint3 Location;
    };

    struct LOADED_REF_DATA
    {
      TESObjectREFR* pCurrentWaterObject;
      int iUnderwaterCount;
      float fRelevantWaterHeight;
      float fCachedRadius;
      unsigned int iFlags;
      NiPointer<NiAVObject> m_spData3D;
      NiPointer<bhkPhantom> spPhantom;
    };


    TESSound *pRandomSound;
    OBJ_REFR data;
    float fRefScale;
    TESObjectCELL *pParentCell;
    ExtraDataList m_Extra;
    LOADED_REF_DATA *pLoadedData;
};

static_assert(sizeof(TESObjectREFR) == 0x68, "TESObjectREFR has wrong size");
