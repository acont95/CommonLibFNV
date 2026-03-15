#pragma once
#include <cstdint>
#include "Bethesda/BaseFormComponent.hpp"
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/TESFile.hpp"

class TESForm : public BaseFormComponent {
  public:
    TESForm();
    ~TESForm();
    std::uint8_t cFormType;
    std::uint32_t iFormFlags;
    std::uint32_t iFormID;
    BSSimpleList<TESFile *> pSourceFiles;
};

static_assert(sizeof(TESForm) == 0x18, "TESForm has wrong size");
