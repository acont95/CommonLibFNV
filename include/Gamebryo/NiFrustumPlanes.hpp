#pragma once
#include <cstdint>
#include "Gamebryo/NiPlane.hpp" 

class NiFrustumPlanes
{
  public:
    NiFrustumPlanes();
    ~NiFrustumPlanes();

    NiPlane m_akCullingPlanes[6];
    std::uint32_t m_uiActivePlanes;
};

static_assert(sizeof(NiFrustumPlanes) == 0x64, "NiFrustumPlanes has wrong size");
