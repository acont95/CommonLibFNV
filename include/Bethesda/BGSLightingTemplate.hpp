#pragma once
#include "Types.hpp"
#include "Bethesda/TESForm.hpp"

namespace CommonLib {

  class BGSLightingTemplate : public TESForm
  {
    public:
      BGSLightingTemplate();
      virtual ~BGSLightingTemplate();

      INTERIOR_DATA Data;
  };

  static_assert(sizeof(BGSLightingTemplate) == 0x44, "BGSLightingTemplate has wrong size");
  
} // namespace CommonLib
