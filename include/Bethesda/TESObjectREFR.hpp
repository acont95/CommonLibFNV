#pragma once
#include <cstdint>
#include "Bethesda/ExtraDataList.hpp"
#include "Bethesda/TESChildCell.hpp"
#include "Bethesda/TESForm.hpp"
#include "Bethesda/bhkPhantom.hpp"
#include "Gamebryo/NiAVObject.hpp"

namespace CommonLib {

  class TESSound;
  class TESBoundObject;
  class TESObjectCELL;

  class TESObjectREFR : public TESForm, public TESChildCell
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
        std::int32_t iUnderwaterCount;
        float fRelevantWaterHeight;
        float fCachedRadius;
        std::uint32_t iFlags;
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
  
} // namespace CommonLib
