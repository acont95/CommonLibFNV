#pragma once
#include <cstdint>
#include "Bethesda/TESBoundObject.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/TESScriptableForm.hpp"
#include "Bethesda/TESEnchantableForm.hpp"
#include "Bethesda/TESValueForm.hpp"
#include "Bethesda/TESWeightForm.hpp"
#include "Bethesda/TESHealthForm.hpp"
#include "Bethesda/TESBipedModelForm.hpp"
#include "Bethesda/BGSDestructibleObjectForm.hpp"
#include "Bethesda/BGSEquipType.hpp"
#include "Bethesda/BGSRepairItemList.hpp"
#include "Bethesda/BGSBipedModelList.hpp"
#include "Bethesda/BGSPickupPutdownSounds.hpp"

namespace CommonLib {

  class FOLEY_SOUND;

  struct OBJ_ARMO
  {
    std::uint16_t sRating;
    float fDamageThreshold;
    std::uint8_t cFlags;
    std::uint8_t cConditionLevel;
  };

  class TESObjectARMO : public TESBoundObject, 
    public TESFullName, 
    public TESScriptableForm, 
    public TESEnchantableForm, 
    public TESValueForm, 
    public TESWeightForm, 
    public TESHealthForm, 
    public TESBipedModelForm, 
    public BGSDestructibleObjectForm, 
    public BGSEquipType, 
    public BGSRepairItemList, 
    public BGSBipedModelList, 
    public BGSPickupPutdownSounds 
  {
    public:
      virtual ~TESObjectARMO();

      OBJ_ARMO data;
      std::uint32_t flags;
      union
      {
        BSSimpleList<FOLEY_SOUND *> *pFoleySoundList;
        TESObjectARMO *pFoleyTemplate;
      };
      bool bIsFoleyBase;
  };

  static_assert(sizeof(TESObjectARMO) == 0x190, "TESObjectARMO has wrong size");
  
} // namespace CommonLib
