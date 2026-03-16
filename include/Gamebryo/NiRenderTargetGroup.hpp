#pragma once
#include <cstdint>
#include "Gamebryo/NiDepthStencilBuffer.hpp"

namespace CommonLib {

  class NiRenderTargetGroup : public NiObject
  {
    public:
      NiRenderTargetGroup();
      virtual ~NiRenderTargetGroup();

      enum MaxRenderBuffers
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
      std::uint32_t uiDepthBase;
      bool bResolveDepth;
      NiPointer<Ni2DBuffer> m_aspBuffers[4];
      std::uint32_t m_uiNumBuffers;
      NiPointer<NiDepthStencilBuffer> m_spDepthStencilBuffer;
      RendererData* m_pkRendererData;
  };

  static_assert(sizeof(NiRenderTargetGroup) == 0x30, "NiRenderTargetGroup has wrong size");
  
} // namespace CommonLib
