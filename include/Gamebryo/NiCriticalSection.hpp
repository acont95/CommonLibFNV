#pragma once
#include <Windows.h>
#include <cstdint>

namespace CommonLib {

  class NiCriticalSection
  {
    public:

      CRITICAL_SECTION m_kCriticalSection;
      std::uint32_t m_ulThreadOwner;
      std::uint32_t m_uiLockCount;
  };

  static_assert(sizeof(NiCriticalSection) == 0x20, "NiCriticalSection has wrong size");
  
} // namespace CommonLib
