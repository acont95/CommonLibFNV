#pragma once
#include <cstdint>
#include "Bethesda/TESForm.hpp"

class BGSListForm : public TESForm
{
  public:
    BGSListForm();
    virtual ~BGSListForm();

    BSSimpleList<TESForm *> ListOfForms;
    std::uint32_t iScriptAddedFormCount;
};

static_assert(sizeof(BGSListForm) == 0x24, "BGSListForm has wrong size");
