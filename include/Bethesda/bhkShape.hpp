#pragma once
#include "Bethesda/bhkSerializable.hpp"

namespace CommonLib {

  class bhkShape : public bhkSerializable
  {
    public:
      bhkShape();
      virtual ~bhkShape();

      unsigned int eMaterial;
  };

  static_assert(sizeof(bhkShape) == 0x14, "bhkShape has wrong size");
  
} // namespace CommonLib
