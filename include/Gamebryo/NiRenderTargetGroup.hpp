#pragma once
#include <cstdint>
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/Ni2DBuffer.hpp"
#include "Gamebryo/NiDepthStencilBuffer.hpp"

class NiRenderTargetGroup : NiObject
{
  public:
    NiRenderTargetGroup();
    virtual ~NiRenderTargetGroup();

    enum MaxRenderBuffers : std::int32_t
    {
      MAX_RENDER_BUFFERS = 0x4,
    };

    class RendererData
    {
      public:
        RendererData();
        virtual ~RendererData();
    };

    bool bForceNoMSAASurface;
    bool bAddDSRestoreSurface;
    unsigned int uiDepthBase;
    bool bResolveDepth;
    NiPointer<Ni2DBuffer> m_aspBuffers[4];
    unsigned int m_uiNumBuffers;
    NiPointer<NiDepthStencilBuffer> m_spDepthStencilBuffer;
    RendererData* m_pkRendererData;
};

static_assert(sizeof(NiRenderTargetGroup) == 0x30, "NiRenderTargetGroup has wrong size");
