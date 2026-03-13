#pragma once
#include "Bethesda/BaseFormComponent.hpp"
#include "Bethesda/BSStringT.hpp"

class TESFullName : BaseFormComponent {
  public:
    TESFullName();
    ~TESFullName();

    BSStringT<char> cFullName;
};

static_assert(sizeof(TESFullName) == 0xC, "TESFullName has wrong size");
