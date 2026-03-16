#pragma once
#include <cstdint>

class BSExtraData;

class BaseExtraList {
  public:
    BaseExtraList();
    virtual ~BaseExtraList();

    BSExtraData* pHead;
    std::uint8_t iFlags[21];
};

static_assert(sizeof(BaseExtraList) == 0x20, "BaseExtraList has wrong size");
