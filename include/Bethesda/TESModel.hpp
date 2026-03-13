#pragma once
#include <cstdint>
#include "Bethesda/BaseFormComponent.hpp"
#include "Bethesda/BSStringT.hpp"
#include "Bethesda/TESTextureList.hpp"

class TESModel : BaseFormComponent {
  public:
    TESModel();
    ~TESModel();

    BSStringT<char> cModel;
    TESTextureList TextureList;
    std::uint8_t cFlags;
};

static_assert(sizeof(TESModel) == 0x18, "TESModel has wrong size");
