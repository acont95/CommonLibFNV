#pragma once
#include "Bethesda/bhkWorldObject.hpp"

namespace CommonLib {

  class bhkEntity : public bhkWorldObject
  {
    public:
      bhkEntity();
      ~bhkEntity();
  };

  static_assert(sizeof(bhkEntity) == 0x14, "bhkEntity has wrong size");
  
} // namespace CommonLib
