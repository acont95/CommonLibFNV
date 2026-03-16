#pragma once
#include <cstdint>
#include "Gamebryo/NiMemObject.hpp"

namespace CommonLib {

  class NiObjectGroup : public NiMemObject {
    public:
      NiObjectGroup();
      ~NiObjectGroup();

      std::uint32_t m_uiSize;
      void* m_pvBuffer;
      void* m_pvFree;
      std::uint32_t m_uiRefCount;
  };

  static_assert(sizeof(NiObjectGroup) == 0x10, "NiObjectGroup has wrong size");
  
} // namespace CommonLib
