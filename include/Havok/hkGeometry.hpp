#pragma once
#include "Havok/hkArray.hpp"
#include "Havok/hkVector4.hpp"
#include "Havok/hkContainerHeapAllocator.hpp"

class hkGeometry
{
  public:
    hkGeometry();
    ~hkGeometry();

    struct Triangle
    {
      int m_a;
      int m_b;
      int m_c;
      int m_material;
    };

    hkArray<hkVector4, hkContainerHeapAllocator> m_vertices;
    hkArray<Triangle, hkContainerHeapAllocator> m_triangles;
};

static_assert(sizeof(hkGeometry) == 0x18, "hkGeometry has wrong size");
