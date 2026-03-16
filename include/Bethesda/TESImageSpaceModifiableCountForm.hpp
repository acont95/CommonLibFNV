#pragma once
#include "Bethesda/BaseFormComponent.hpp"

class TESImageSpaceModifier;

template <size_t T>
class TESImageSpaceModifiableCountForm : public BaseFormComponent
{
  
  public:
    TESImageSpaceModifiableCountForm();
    virtual ~TESImageSpaceModifiableCountForm();

    TESImageSpaceModifier* pFormImageSpaceModifying[T];
};

static_assert(sizeof(TESImageSpaceModifiableCountForm<6>) == 0x1C, "TESImageSpaceModifiableCountForm has wrong size");
