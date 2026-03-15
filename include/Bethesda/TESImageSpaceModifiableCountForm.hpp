#pragma once
#include "Bethesda/TESImageSpaceModifier.hpp"
#include "Bethesda/BaseFormComponent.hpp"

template <size_t T>
class TESImageSpaceModifiableCountForm : BaseFormComponent
{
  public:
    TESImageSpaceModifiableCountForm();
    virtual ~TESImageSpaceModifiableCountForm();

    TESImageSpaceModifier* pFormImageSpaceModifying[T];
};

static_assert(sizeof(TESImageSpaceModifiableCountForm<6>) == 0x1C, "TESImageSpaceModifiableCountForm has wrong size");
