#pragma once
#include <cstdint>
#include "Bethesda/TESForm.hpp"
#include "Bethesda/BGSPreloadable.hpp"
#include "Bethesda/BSSimpleList.hpp"

namespace CommonLib {

  class BGSDebrisData;

  class BGSDebris : public TESForm, public BGSPreloadable
  {
    public:

      BSSimpleList<BGSDebrisData*> DataList;
  };

  static_assert(sizeof(BGSDebris) == 0x24, "BGSDebris has wrong size");
  
} // namespace CommonLib
