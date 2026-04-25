#pragma once
#include "Havok/hkContactPoint.hpp"

namespace CommonLib {

  class hkpCollidable;

  class alignas(16) hkpRootCdPoint
  {
    public:
      hkpRootCdPoint();
      ~hkpRootCdPoint();

      hkContactPoint m_contact;
      const hkpCollidable *m_rootCollidableA;
      unsigned int m_shapeKeyA;
      unsigned int m_shapeKeysA[8];
      const hkpCollidable *m_rootCollidableB;
      unsigned int m_shapeKeyB;
      unsigned int m_shapeKeysB[8];
  };

  static_assert(sizeof(hkpRootCdPoint) == 0x70, "hkpRootCdPoint has wrong size");
  
} // namespace CommonLib
