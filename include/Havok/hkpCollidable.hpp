#pragma once
#include <cstdint>
#include "Havok/hkpTypedBroadPhaseHandle.hpp"
#include "Havok/hkpCdBody.hpp"

namespace CommonLib {

  class hkAabbUint32;

  class hkpCollidable : public hkpCdBody
  {
    public:

      class BoundingVolumeData
      {
        public:
          std::uint32_t m_min[3];
          std::uint8_t m_expansionMin[3];
          std::uint8_t m_expansionShift;
          std::uint32_t m_max[3];
          std::uint8_t m_expansionMax[3];
          std::uint8_t m_padding;
          std::uint16_t m_numChildShapeAabbs;
          std::uint16_t m_capacityChildShapeAabbs;
          hkAabbUint32 *m_childShapeAabbs;
          std::uint32_t *m_childShapeKeys;
      };

      char m_ownerOffset;
      std::uint8_t m_forceCollideOntoPpu;
      std::uint16_t m_shapeSizeOnSpu;
      hkpTypedBroadPhaseHandle m_broadPhaseHandle;
      BoundingVolumeData m_boundingVolumeData;
      float m_allowedPenetrationDepth;
  };

  static_assert(sizeof(hkpCollidable) == 0x50, "hkpCollidable has wrong size");
  
} // namespace CommonLib
