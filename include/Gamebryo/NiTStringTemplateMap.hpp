#pragma once
#include "Gamebryo/NiTMap.hpp"

template <class TParent, typename T>
class NiTStringTemplateMap : TParent
{
  public:
    NiTStringTemplateMap();
    virtual ~NiTStringTemplateMap();

    bool m_bCopy;
};

static_assert(sizeof(NiTStringTemplateMap<NiTMap<char const*, void*>, void*>) == 0x14, "NiTStringTemplateMap has wrong size");
