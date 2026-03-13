#pragma once
#include "Bethesda/BaseFormComponent.hpp"

class BGSPreloadable : BaseFormComponent
{
  public:
    BGSPreloadable();
    ~BGSPreloadable();
};

static_assert(sizeof(BGSPreloadable) == 0x4, "BGSPreloadable has wrong size");
