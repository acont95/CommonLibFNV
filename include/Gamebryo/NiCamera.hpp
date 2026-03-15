#pragma once
#include "Gamebryo/NiAVObject.hpp"
#include "Gamebryo/NiFrustum.hpp"
#include "Gamebryo/NiRect.hpp"

class NiCamera : public NiAVObject
{
  public:
    NiCamera();
    virtual ~NiCamera();

    float m_aafWorldToCam[4][4];
    NiFrustum m_kViewFrustum;
    float m_fMinNearPlaneDist;
    float m_fMaxFarNearRatio;
    NiRect<float> m_kPort;
    float m_fLODAdjust;
};

static_assert(sizeof(NiCamera) == 0x114, "NiCamera has wrong size");
