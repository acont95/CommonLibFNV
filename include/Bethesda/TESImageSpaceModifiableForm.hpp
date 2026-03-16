#pragma once
#include "Bethesda/BaseFormComponent.hpp"

namespace CommonLib {

  class TESImageSpaceModifier;

  class TESImageSpaceModifiableForm : public BaseFormComponent
  {
    public:
      TESImageSpaceModifiableForm();
      ~TESImageSpaceModifiableForm();

      TESImageSpaceModifier* pFormImageSpaceModifying;
  };

  static_assert(sizeof(TESImageSpaceModifiableForm) == 0x8, "TESImageSpaceModifiableForm has wrong size");
  
} // namespace CommonLib
