#pragma once
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiFixedString.hpp"

class NiExtraData : NiObject {
  public:
    NiExtraData();
    ~NiExtraData();

    NiFixedString m_kName;
};

static_assert(sizeof(NiExtraData) == 0xC, "NiExtraData has wrong size");
