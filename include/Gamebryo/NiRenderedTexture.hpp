#pragma once
#include <cstdint>
#include <d3d9types.h>
#include "Gamebryo/Ni2DBuffer.hpp"
#include "Gamebryo/NiTexture.hpp"

class NiRenderedTexture : public NiTexture
{
  public:
    NiRenderedTexture();
    virtual ~NiRenderedTexture();

    NiPointer<Ni2DBuffer> m_spBuffer;
    std::uint32_t uiAliasOffset;
    NiRenderedTexture* pAliasTexture;
    Ni2DBuffer::MultiSamplePreference eMSAA;
    bool bRenderedTexture;
    bool bForceD3DFormat;
    D3DFORMAT iForcedD3DFormat;
};

static_assert(sizeof(NiRenderedTexture) == 0x48, "NiRenderedTexture has wrong size");
