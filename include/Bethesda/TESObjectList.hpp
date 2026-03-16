#pragma once
#include <cstdint>

class TESObject;
class TESObjectCELL;

class TESObjectList {
  public:
    TESObjectList();
    ~TESObjectList();

    std::uint32_t lnk_dwCount;
    TESObject *lnk_lpRoot;
    TESObject *lnk_lpTail;
    TESObjectCELL *pOwner;
};
