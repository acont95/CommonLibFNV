#pragma once
#include "Bethesda/BaseExtraList.hpp"

class ExtraDataList : BaseExtraList {
  public:
    ExtraDataList();
    ~ExtraDataList();
};

static_assert(sizeof(ExtraDataList) == 0x20, "ExtraDataList has wrong size");
