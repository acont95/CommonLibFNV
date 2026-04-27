#pragma once
#include <cstdint>
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiAnimationKey.hpp"

namespace CommonLib {

  class NiColorKey;

  class NiColorData : public NiObject
  {
    public:

      std::uint32_t m_uiNumKeys;
      NiColorKey* m_pkKeys;
      NiAnimationKey::KeyType m_eType;
      std::uint8_t m_ucKeySize;
  };

  static_assert(sizeof(NiColorData) == 0x18, "NiColorData has wrong size");
  
} // namespace CommonLib
