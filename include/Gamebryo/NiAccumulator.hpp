#pragma once
#include "Gamebryo/NiObject.hpp"

namespace CommonLib {

  class NiCamera;

  class NiAccumulator : public NiObject {
    public:
      NiAccumulator();
      ~NiAccumulator();

      const NiCamera *m_pkCamera;
  };

  static_assert(sizeof(NiAccumulator) == 0xC, "BSExtraData has wrong size");
  
} // namespace CommonLib
