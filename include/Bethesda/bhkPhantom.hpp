#pragma once
#include <cstdint>
#include "Bethesda/bhkWorldObject.hpp"

namespace CommonLib {

  class bhkPhantom : public bhkWorldObject
  {
    public:
      bhkPhantom();
      ~bhkPhantom();

      std::uint8_t cFlags;
  };

  static_assert(sizeof(bhkPhantom) == 0x18, "bhkPhantom has wrong size");
  
} // namespace CommonLib
