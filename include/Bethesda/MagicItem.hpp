#pragma once
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/EffectItemList.hpp"

namespace CommonLib {

  class MagicItem : public TESFullName, public EffectItemList 
  {
    public:

      enum CannotCastReason 
      {
        NOCAST_OK = 0x0,
        NOCAST_MAGICKA = 0x1,
        NOCAST_SILENCED = 0x2,
        NOCAST_SKILLCHECK = 0x3,
        NOCAST_POWERUSED = 0x4,
        NOCAST_MULTIPLEBOUNDEFFECTS = 0x5,
        NOCAST_RANGEDUNDERWATER = 0x6,
      };

  };

  static_assert(sizeof(MagicItem) == 0x1C, "MagicItem has wrong size");
  
} // namespace CommonLib
