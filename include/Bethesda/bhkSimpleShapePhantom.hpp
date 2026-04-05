#pragma once
#include "Bethesda/bhkShapePhantom.hpp"

namespace CommonLib {

  class bhkSimpleShapePhantom : public bhkShapePhantom
  {
    public:
      bhkSimpleShapePhantom();
      virtual ~bhkSimpleShapePhantom();
  };

  static_assert(sizeof(bhkSimpleShapePhantom) == 0x18, "bhkSimpleShapePhantom has wrong size");
  
} // namespace CommonLib
