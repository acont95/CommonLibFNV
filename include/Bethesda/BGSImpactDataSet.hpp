#pragma once
#include "Bethesda/TESForm.hpp"
#include "Bethesda/BGSPreloadable.hpp"

namespace CommonLib {

  class BGSImpactData;

  class BGSImpactDataSet : public TESForm, public BGSPreloadable
  {
    public:
      BGSImpactDataSet();
      ~BGSImpactDataSet();

      BGSImpactData *ppImpactData[12];
  };

  static_assert(sizeof(BGSImpactDataSet) == 0x4C, "BGSImpactDataSet has wrong size");
  
} // namespace CommonLib
