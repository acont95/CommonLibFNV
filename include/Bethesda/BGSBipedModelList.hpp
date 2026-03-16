#pragma once
#include "Bethesda/BaseFormComponent.hpp"

class BGSListForm;

class BGSBipedModelList : public BaseFormComponent
{
  public:
    BGSBipedModelList();
    virtual ~BGSBipedModelList();

    BGSListForm *pListForm;
};

static_assert(sizeof(BGSBipedModelList) == 0x8, "BGSBipedModelList has wrong size");
