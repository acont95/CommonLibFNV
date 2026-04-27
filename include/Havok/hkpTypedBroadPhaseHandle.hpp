#pragma once
#include <cstdint>
#include "Havok/hkpBroadPhaseHandle.hpp"

namespace CommonLib {


  class hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle
  {
    public:

      char m_type;
      char m_ownerOffset;
      char m_objectQualityType;
      std::uint32_t m_collisionFilterInfo;
  };

  static_assert(sizeof(hkpTypedBroadPhaseHandle) == 0xC, "hkpTypedBroadPhaseHandle has wrong size");
  
} // namespace CommonLib
