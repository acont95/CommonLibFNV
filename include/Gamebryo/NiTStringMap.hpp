#pragma once
#include "Bethesda/TESForm.hpp"
#include "Gamebryo/NiTMap.hpp"
#include "Gamebryo/NiTStringTemplateMap.hpp"

template <typename T>
class NiTStringMap : NiTStringTemplateMap<NiTMap<char const*, T>, T>
{
  public:
    NiTStringMap();
    virtual ~NiTStringMap();

};

static_assert(sizeof(NiTStringMap<void*>) == 0x14, "NiTStringMap has wrong size");
