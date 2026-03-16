#pragma once
#include <cstdint>
#include "Bethesda/BaseFormComponent.hpp"

namespace CommonLib {

  class BGSEquipType : public BaseFormComponent
  {
    public:
      BGSEquipType();
      virtual ~BGSEquipType();

      enum EQUIP_TYPE
      {
        ET_NONE = 0xFFFFFFFF,
        ET_BIG_GUN = 0x0,
        ET_ENERGY_WEAPON = 0x1,
        ET_SMALL_GUN = 0x2,
        ET_MELEE_WEAPON = 0x3,
        ET_UNARMED_WEAPON = 0x4,
        ET_THROWN_WEAPON = 0x5,
        ET_MINE = 0x6,
        ET_BODY_WEAR = 0x7,
        ET_HEAD_WEAR = 0x8,
        ET_HAND_WEAR = 0x9,
        ET_CHEMS = 0xA,
        ET_STIMPACK = 0xB,
        ET_FOOD = 0xC,
        ET_ALCOHOL = 0xD,
        ET_COUNT = 0xE,
      };

      EQUIP_TYPE eEquipType;
  };

  static_assert(sizeof(BGSEquipType) == 0x8, "BGSEquipType has wrong size");
  
} // namespace CommonLib
