#pragma once
#include <cstdint>
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiAnimationKey.hpp"

class NiFloatKey;

class NiFloatData : public NiObject
{
  public:
    NiFloatData();
    ~NiFloatData();

    std::uint32_t m_uiNumKeys;
    NiFloatKey *m_pkKeys;
    NiAnimationKey::KeyType m_eType;
    std::uint8_t m_ucKeySize;
};

static_assert(sizeof(NiFloatData) == 0x18, "NiFloatData has wrong size");
