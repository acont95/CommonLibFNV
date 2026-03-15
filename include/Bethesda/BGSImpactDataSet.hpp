#pragma once
#include "Bethesda/TESForm.hpp"
#include "Bethesda/BGSPreloadable.hpp"
#include "Bethesda/BGSImpactData.hpp"

class BGSImpactDataSet : TESForm, BGSPreloadable
{
  public:
    BGSImpactDataSet();
    ~BGSImpactDataSet();

    BGSImpactData *ppImpactData[12];
};

static_assert(sizeof(BGSImpactDataSet) == 0x4C, "BGSImpactDataSet has wrong size");
