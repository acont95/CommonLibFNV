#pragma once
#include "Bethesda/BaseFormComponent.hpp"

namespace CommonLib {

  class BGSPreloadable : public BaseFormComponent
  {
    public:

  };

  static_assert(sizeof(BGSPreloadable) == 0x4, "BGSPreloadable has wrong size");
  
} // namespace CommonLib
