#pragma once

class NiFrustum
{
  public:
    NiFrustum();
    ~NiFrustum();

    float m_fLeft;
    float m_fRight;
    float m_fTop;
    float m_fBottom;
    float m_fNear;
    float m_fFar;
    bool m_bOrtho;
};

static_assert(sizeof(NiFrustum) == 0x1C, "NiFrustum has wrong size");
