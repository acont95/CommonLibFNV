#pragma once
#include "Gamebryo/NiRefObject.hpp"
#include "Gamebryo/NiFixedString.hpp"

class NiShader : NiRefObject
{
  public:
    NiShader();
    ~NiShader();

    NiFixedString m_kName;
    unsigned int m_uiImplementation;
    bool m_bInitialized;
};

static_assert(sizeof(NiShader) == 0x14, "NiShader has wrong size");
