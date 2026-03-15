#pragma once
#include "Bethesda/BGSListForm.hpp"

class BGSBipedModelList : BaseFormComponent
{
  public:
    BGSBipedModelList();
    virtual ~BGSBipedModelList();

    BGSListForm *pListForm;
};

static_assert(sizeof(BGSBipedModelList) == 0x8, "BGSBipedModelList has wrong size");
