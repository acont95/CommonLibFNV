#pragma once
#include <cstdint>
#include "Gamebryo/NiRenderTargetGroup.hpp"
#include "Gamebryo/NiRenderedTexture.hpp"

namespace CommonLib {

  class BSRenderedTexture : public NiObject
  {
    public:
      BSRenderedTexture();
      virtual ~BSRenderedTexture();

      NiPointer<NiRenderTargetGroup> spGroup[6];
      NiPointer<NiRenderTargetGroup> spPreRestoreGroup;
      NiPointer<NiRenderTargetGroup> spRestoreGroup;
      NiPointer<NiRenderTargetGroup> spPostRestoreGroup;
      std::int32_t iAliasedType;
      NiPointer<NiRenderedTexture> spTexture[4];
  };

  static_assert(sizeof(BSRenderedTexture) == 0x40, "BSRenderedTexture has wrong size");

  
} // namespace CommonLib
