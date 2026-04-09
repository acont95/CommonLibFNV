#pragma once
#include <cstdint>
#include "Gamebryo/NiRenderTargetGroup.hpp"
#include "Gamebryo/NiRenderedTexture.hpp"

namespace CommonLib {

  class BSReference : public NiObject
  {
    public:
      BSReference();
      virtual ~BSReference();

      char *pName;
  };

  static_assert(sizeof(BSReference) == 0xC, "BSReference has wrong size");

  
} // namespace CommonLib
