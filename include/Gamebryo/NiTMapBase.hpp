#pragma once
#include <cstdint>
#include "Gamebryo/NiMemObject.hpp"
#include "Gamebryo/NiTDefaultAllocator.hpp"

namespace CommonLib {

  class TESForm;
  template <typename Key, typename Value>
  class NiTMapItem;

  template <class TAllocator, typename Key, typename Value>
  class NiTMapBase : public NiMemObject
  {
    public:
      virtual ~NiTMapBase() = default;

      class AntiBloatAllocator : public TAllocator
      {
        public:
          std::uint32_t m_uiCount;
      };

      std::uint32_t m_uiHashSize;
      NiTMapItem<std::uint32_t, TESForm*>** m_ppkHashTable;
      AntiBloatAllocator m_kAllocator;
  };

  static_assert(sizeof(NiTMapBase<NiTDefaultAllocator<void*>, void*, void*>) == 0x10, "NiTMapBase has wrong size");  
  
} // namespace CommonLib
