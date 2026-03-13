#pragma once
#include "Gamebryo/NiPlane.hpp" 

class NiFrustumPlanes
{
  public:
    NiFrustumPlanes();
    ~NiFrustumPlanes();

    NiPlane m_akCullingPlanes[6];
    unsigned int m_uiActivePlanes;
};

static_assert(sizeof(NiFrustumPlanes) == 0x64, "NiFrustumPlanes has wrong size");
