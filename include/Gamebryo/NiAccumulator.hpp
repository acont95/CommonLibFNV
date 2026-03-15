#pragma once
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiCamera.hpp"

class NiAccumulator : NiObject {
  public:
    NiAccumulator();
    ~NiAccumulator();

    const NiCamera *m_pkCamera;
};

static_assert(sizeof(NiAccumulator) == 0xC, "BSExtraData has wrong size");