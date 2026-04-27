#pragma once
#include "Bethesda/BaseFormComponent.hpp"

namespace CommonLib {

  class TESImageSpaceModifier;

  class TESImageSpaceModifiableForm : public BaseFormComponent
  {
    public:

      TESImageSpaceModifier* pFormImageSpaceModifying;
  };

  static_assert(sizeof(TESImageSpaceModifiableForm) == 0x8, "TESImageSpaceModifiableForm has wrong size");
  
} // namespace CommonLib
