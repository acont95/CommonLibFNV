#pragma once
#include "Bethesda/bhkPhantom.hpp"

namespace CommonLib {

  class bhkShapePhantom : public bhkPhantom
  {
    public:
      bhkShapePhantom();
      virtual ~bhkShapePhantom();
  };

  static_assert(sizeof(bhkShapePhantom) == 0x18, "bhkShapePhantom has wrong size");
  
} // namespace CommonLib
