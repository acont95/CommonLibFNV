#pragma once
#include <cstdint>

namespace CommonLib {

  class NiGeometry;

  class NiVisibleArray
  {
    public:

      NiGeometry** m_ppkArray;
      std::uint32_t m_uiCurrentSize;
      std::uint32_t m_uiAllocatedSize;
      std::uint32_t m_uiGrowBy;
  };

  static_assert(sizeof(NiVisibleArray) == 0x10, "NiVisibleArray has wrong size");
  
} // namespace CommonLib
