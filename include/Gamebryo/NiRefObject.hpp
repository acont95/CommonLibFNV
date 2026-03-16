#pragma once
#include <cstdint>

namespace CommonLib {

  class NiRefObject
  {
    public:
      NiRefObject();
      virtual ~NiRefObject();

      std::uint32_t m_uiRefCount;
  };

  static_assert(sizeof(NiRefObject) == 0x8, "NiRefObject has wrong size");
  
} // namespace CommonLib
