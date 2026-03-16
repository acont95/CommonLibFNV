#pragma once
#include "Bethesda/BaseFormComponent.hpp"

namespace CommonLib {

  class TESForm;

  class BGSAmmoForm : public BaseFormComponent
  {
    public:
      BGSAmmoForm();
      virtual ~BGSAmmoForm();

      TESForm *pFormAmmo;
  };

  static_assert(sizeof(BGSAmmoForm) == 0x8, "BGSAmmoForm has wrong size");
  
} // namespace CommonLib
