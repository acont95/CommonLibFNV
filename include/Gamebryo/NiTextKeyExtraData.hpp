#pragma once
#include <cstdint>
#include "Gamebryo/NiExtraData.hpp"

namespace CommonLib {

  class NiTextKey;

  class NiTextKeyExtraData : public NiExtraData
  {
    public:
      virtual ~NiTextKeyExtraData();

      unsigned int m_uiNumKeys;
      NiTextKey *m_pKeys;
  };

  static_assert(sizeof(NiTextKeyExtraData) == 0x14, "NiTextKeyExtraData has wrong size");
  
} // namespace CommonLib
