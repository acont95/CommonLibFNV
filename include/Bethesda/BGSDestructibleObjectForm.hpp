#pragma once
#include "Bethesda/BaseFormComponent.hpp"

class DestructibleObjectData;

class BGSDestructibleObjectForm : public BaseFormComponent
{
  public:
    BGSDestructibleObjectForm();
    ~BGSDestructibleObjectForm();

    DestructibleObjectData *pData;
};

static_assert(sizeof(BGSDestructibleObjectForm) == 0x8);
