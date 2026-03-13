#pragma once
#include <cstdint>

class TESObjectLIGH {
  public:
    TESObjectLIGH();
    ~TESObjectLIGH();

    struct OBJ_LIGH
    {
      std::int32_t time;
      std::uint32_t radius;
      std::uint32_t color;
      std::uint32_t flags;
      float fFallOffExponent;
      float fFOV;
    };

    OBJ_LIGH data;
    float fFade;
    TESSound *m_pSound;
    NiColor EmittanceColor;
};
