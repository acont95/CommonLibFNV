#pragma once
#include "Gamebryo/NiGeometry.hpp"

namespace CommonLib {

  class NiTriBasedGeom : public NiGeometry
  {
    public:
      NiTriBasedGeom();
      virtual ~NiTriBasedGeom();
  };

  static_assert(sizeof(NiTriBasedGeom) == 0xC4, "NiTriBasedGeom has wrong size");
  
} // namespace CommonLib
