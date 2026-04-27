#pragma once
#include <cstdint>
#include "Havok/hkArray.hpp"
#include "Havok/hkVector4.hpp"
#include "Havok/hkContainerHeapAllocator.hpp"

namespace CommonLib {

  class hkGeometry
  {
    public:

      struct Triangle
      {
        std::int32_t m_a;
        std::int32_t m_b;
        std::int32_t m_c;
        std::int32_t m_material;
      };

      hkArray<hkVector4, hkContainerHeapAllocator> m_vertices;
      hkArray<Triangle, hkContainerHeapAllocator> m_triangles;
  };

  static_assert(sizeof(hkGeometry) == 0x18, "hkGeometry has wrong size");
  
} // namespace CommonLib
