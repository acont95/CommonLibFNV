#pragma once
#include "Bethesda/BaseExtraList.hpp"

namespace CommonLib {

  class ExtraDataList : public BaseExtraList {
    public:

  };

  static_assert(sizeof(ExtraDataList) == 0x20, "ExtraDataList has wrong size");
  
} // namespace CommonLib
