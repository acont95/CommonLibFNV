#pragma once
#include "Gamebryo/NiTStringTemplateMap.hpp"

template <typename T>
class NiTStringMap : public NiTStringTemplateMap<NiTMap<char const*, T>, T>
{
  public:
    NiTStringMap();
    virtual ~NiTStringMap();

};

static_assert(sizeof(NiTStringMap<void*>) == 0x14, "NiTStringMap has wrong size");
