#pragma once
#include "Bethesda/BaseFormComponent.hpp"
#include "Bethesda/DestructibleObjectData.hpp"

class BGSDestructibleObjectForm : BaseFormComponent
{
  public:
    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm();

    DestructibleObjectData *pData;
};

static_assert(sizeof(BGSDestructibleObjectForm) == 0x8);
