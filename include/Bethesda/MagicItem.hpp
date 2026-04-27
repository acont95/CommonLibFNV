#pragma once
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/EffectItemList.hpp"

namespace CommonLib {

  class MagicItem : public TESFullName, public EffectItemList 
  {
    public:

  };

  static_assert(sizeof(MagicItem) == 0x1C, "MagicItem has wrong size");
  
} // namespace CommonLib
