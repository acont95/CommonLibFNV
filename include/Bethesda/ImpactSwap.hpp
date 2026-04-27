#pragma once

namespace CommonLib {

  class BGSImpactData;
  template <typename Key, typename Value>
  class BSMap;

  // Need to add type defines
  class ImpactSwap
  {
    public:

      BSMap<BGSImpactData *,BGSImpactData *> *pRemappedData[12];
      char pAltFootstepMaterialNames[10][30];
  };

  static_assert(sizeof(ImpactSwap) == 0x15C);
  
} // namespace CommonLib
