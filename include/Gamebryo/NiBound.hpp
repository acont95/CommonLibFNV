#pragma once
#include <cstdint>
#include "Gamebryo/NiPoint3.hpp"

namespace CommonLib {

  class NiBound
  {
    public:

      union NiBoundRadius
      {
        float m_fRadius;
        std::int32_t m_iRadiusAsInt;
      };

      NiPoint3 m_kCenter;
      NiBoundRadius m_kRadius;
  };

  static_assert(sizeof(NiBound) == 0x10, "NiBound has wrong size");
  
} // namespace CommonLib
