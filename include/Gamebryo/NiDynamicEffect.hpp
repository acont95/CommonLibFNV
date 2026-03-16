#pragma once
#include <cstdint>
#include "Gamebryo/NiAVObject.hpp"

class NiDynamicEffect : public NiAVObject
{
  public:
    NiDynamicEffect();
    ~NiDynamicEffect();

    bool m_bOn;
    std::uint8_t m_ucEffectType;
    std::int32_t m_iIndex;
    std::uint32_t m_uiPushCount;
    std::uint32_t m_uiRevID;
    NiTPointerList<NiNode*> m_kAffectedNodeList;
    NiTPointerList<NiNode*> m_kUnaffectedNodeList;
};

static_assert(sizeof(NiDynamicEffect) == 0xC4, "NiDynamicEffect has wrong size");
