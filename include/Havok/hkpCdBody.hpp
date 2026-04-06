#pragma once
#include <cstdint>
#include "Havok/hkBool.hpp"

namespace CommonLib {

  class hkpShape;

  class hkpCdBody
  {
    public:
      hkpCdBody();
      ~hkpCdBody();

      const hkpShape *m_shape;
      std::uint32_t m_shapeKey;
      const void *m_motion;
      const hkpCdBody *m_parent;
  };

  static_assert(sizeof(hkpCdBody) == 0x10, "hkpCdBody has wrong size");
  
} // namespace CommonLib
