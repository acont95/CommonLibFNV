#pragma once
#include <cstdint>
#include "Havok/hkVector4.hpp"
#include "Havok/hkBool.hpp"

namespace CommonLib {

  class hkpBroadPhaseHandle
  {
    public:
      hkpBroadPhaseHandle();
      ~hkpBroadPhaseHandle();

      std::uint32_t m_id;
  };

  static_assert(sizeof(hkpBroadPhaseHandle) == 0x4, "hkpBroadPhaseHandle has wrong size");
  
} // namespace CommonLib
