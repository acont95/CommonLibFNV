#pragma once
#include "Types.hpp"
#include "Bethesda/TESForm.hpp"

class BGSLightingTemplate : TESForm
{
  public:
    BGSLightingTemplate();
    virtual ~BGSLightingTemplate();

    INTERIOR_DATA Data;
};

static_assert(sizeof(BGSLightingTemplate) == 0x44, "BGSLightingTemplate has wrong size");
