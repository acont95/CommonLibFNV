#pragma once
#include <cstdint>
#include "Gamebryo/NiTMallocInterface.hpp"

namespace CommonLib {

  class NiTask;

  template <typename T, typename TAllocator>
  class NiTQueue
  {
    public:
      NiTask **m_pBase;
      unsigned int m_uiAlloced;
      unsigned int m_uiHead;
      unsigned int m_uiTail;
  };

  static_assert(sizeof(NiTQueue<void*, NiTMallocInterface<void*>>) == 0x10, "NiTQueue has wrong size");
  
} // namespace CommonLib
