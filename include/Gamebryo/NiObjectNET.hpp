#pragma once
#include <cstdint>
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiObject.hpp"
#include "Gamebryo/NiFixedString.hpp"
#include "Gamebryo/NiTimeController.hpp"

class NiExtraData;

class NiObjectNET : public NiObject {
  public:
    NiObjectNET();
    ~NiObjectNET();

    NiFixedString m_kName;
    NiPointer<NiTimeController> m_spControllers;
    NiExtraData** m_ppkExtra;
    std::uint16_t m_usExtraDataSize;
    std::uint16_t m_usMaxSize;
};

static_assert(sizeof(NiObjectNET) == 0x18, "NiObjectNET has wrong size");
