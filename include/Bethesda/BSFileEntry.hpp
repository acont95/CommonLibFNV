#pragma once
#include <cstdint>
#include "Bethesda/BSHash.hpp"

namespace CommonLib {

  class BSFileEntry : public BSHash {
    public:
      BSFileEntry();
      ~BSFileEntry();

      std::uint32_t iSize;
      std::uint32_t iOffset;
  };

  static_assert(sizeof(BSFileEntry) == 0x10, "BSFileEntry has wrong size");
  
} // namespace CommonLib
