#pragma once
#include "Gamebryo/NiMemObject.hpp"
#include "Gamebryo/NiFrustum.hpp"
#include "Gamebryo/NiFrustumPlanes.hpp"

class NiVisibleArray;
class NiCamera;

class NiCullingProcess : public NiMemObject
{
  public:
    NiCullingProcess();
    virtual ~NiCullingProcess();

    const bool m_bUseVirtualAppend;
    NiVisibleArray* m_pkVisibleSet;
    const NiCamera* m_pkCamera;
    NiFrustum m_kFrustum;
    NiFrustumPlanes m_kPlanes;
};

static_assert(sizeof(NiCullingProcess) == 0x90, "NiCullingProcess has wrong size");
