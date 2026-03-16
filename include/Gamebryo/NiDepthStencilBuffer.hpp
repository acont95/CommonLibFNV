#pragma once
#include "Gamebryo/Ni2DBuffer.hpp"

namespace CommonLib {

  class NiDepthStencilBuffer : public Ni2DBuffer
  {
    public:
      NiDepthStencilBuffer();
      virtual ~NiDepthStencilBuffer();

  };

  static_assert(sizeof(NiDepthStencilBuffer) == 0x14, "NiDepthStencilBuffer has wrong size");
  
} // namespace CommonLib
