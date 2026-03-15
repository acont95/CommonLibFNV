#pragma once
#include <cstdint>
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/TESForm.hpp"

class BGSListForm : TESForm
{
  public:
    BGSListForm();
    virtual ~BGSListForm();

    BSSimpleList<TESForm *> ListOfForms;
    std::uint32_t iScriptAddedFormCount;
};

static_assert(sizeof(BGSListForm) == 0x24, "BGSListForm has wrong size");
