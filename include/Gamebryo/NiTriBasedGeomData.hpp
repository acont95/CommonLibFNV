#pragma once
#include <cstdint>
#include "Gamebryo/NiGeometryData.hpp"

class NiTriBasedGeomData : public NiGeometryData
{
  public:
    NiTriBasedGeomData();
    ~NiTriBasedGeomData();

    std::uint16_t m_usTriangles;
};

static_assert(sizeof(NiTriBasedGeomData) == 0x44, "NiTriBasedGeomData has wrong size");
