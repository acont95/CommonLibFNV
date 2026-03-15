#pragma once
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/Ni2DBuffer.hpp"
#include "Gamebryo/NiRenderedTexture.hpp"
#include "Gamebryo/Ni2DBuffer.hpp"
#include "Gamebryo/NiTexture.hpp"
#include <d3d9types.h>

class NiRenderedTexture : NiTexture
{
  public:
    NiRenderedTexture();
    virtual ~NiRenderedTexture();

    NiPointer<Ni2DBuffer> m_spBuffer;
    unsigned int uiAliasOffset;
    NiRenderedTexture* pAliasTexture;
    Ni2DBuffer::MultiSamplePreference eMSAA;
    bool bRenderedTexture;
    bool bForceD3DFormat;
    D3DFORMAT iForcedD3DFormat;
};

static_assert(sizeof(NiRenderedTexture) == 0x48, "NiRenderedTexture has wrong size");
