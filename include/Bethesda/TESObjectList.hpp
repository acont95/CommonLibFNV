#pragma once
#include <cstdint>
#include "Bethesda/TESObject.hpp"

class TESObjectList {
  public:
    TESObjectList();
    ~TESObjectList();

    std::uint32_t lnk_dwCount;
    TESObject *lnk_lpRoot;
    TESObject *lnk_lpTail;
    TESObjectCELL *pOwner;
};
