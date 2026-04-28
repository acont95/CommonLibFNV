#pragma once
#include "Bethesda/BSSimpleList.hpp"

namespace CommonLib {

  class SpellDispelData;

  class MagicTarget
  {
    public:
      virtual ~MagicTarget();

      bool bShowTargetStats;
      bool bUpdating;
      BSSimpleList<SpellDispelData*> PostUpdateDispelList;
  };

  static_assert(sizeof(MagicTarget) == 0x10, "MagicTarget has wrong size");

} // namespace CommonLib
