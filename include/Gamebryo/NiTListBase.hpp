#pragma once
#include <cstdint>
#include "Gamebryo/NiMemObject.hpp"
#include "Gamebryo/NiTDefaultAllocator.hpp"

namespace CommonLib {

  template <typename T>
  class NiTListItem;

  template <class TAllocator, typename T>
  class NiTListBase : public NiMemObject
  {
    public:

      class AntiBloatAllocator : public TAllocator
      {
        public:
          std::uint32_t m_uiCount;
      };

      NiTListItem<T>* m_pkHead;
      NiTListItem<T>* m_pkTail;
      AntiBloatAllocator m_kAllocator;
  };

  static_assert(sizeof(NiTListBase<NiTDefaultAllocator<void*>, void*>) == 0xC, "NiTListBase has wrong size");
  
} // namespace CommonLib
