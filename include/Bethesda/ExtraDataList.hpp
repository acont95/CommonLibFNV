#pragma once
#include "Bethesda/BaseExtraList.hpp"

namespace CommonLib {

  class ExtraDataList : public BaseExtraList {
    public:
      ExtraDataList();
      ~ExtraDataList();
  };

  static_assert(sizeof(ExtraDataList) == 0x20, "ExtraDataList has wrong size");
  
} // namespace CommonLib
