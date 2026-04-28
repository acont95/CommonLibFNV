#pragma once
#include <cstdint>

namespace CommonLib {

  template <typename T, std::uint32_t N>
  class BSSimpleArray
  {
    public:
      virtual ~BSSimpleArray() = default;

      T* pBuffer;
      std::uint32_t iSize;
      std::uint32_t iReservedSize;
  };

  static_assert(sizeof(BSSimpleArray<void*, 1024>) == 0x10);
  
} // namespace CommonLib
