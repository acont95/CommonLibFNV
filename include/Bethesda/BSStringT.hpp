#pragma once
#include <cstdint>

namespace CommonLib {

  template <typename T>
  class BSStringT {
    public:
      BSStringT();
      ~BSStringT();

      T* pString;
      std::uint16_t sLen;
      std::uint16_t sMaxLen;
  };

  static_assert(sizeof(BSStringT<char>) == 0x8, "BSStringT<char> has wrong size");
  
} // namespace CommonLib
