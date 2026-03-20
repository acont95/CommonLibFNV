#pragma once
#include "Bethesda/bhkSerializable.hpp"

namespace CommonLib {

  class bhkAction : public bhkSerializable
  {
    public:
      bhkAction();
      virtual ~bhkAction();
  };

  static_assert(sizeof(bhkAction) == 0x10, "bhkAction has wrong size");
  
} // namespace CommonLib
