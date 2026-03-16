#pragma once
#include "Gamebryo/NiPoint3.hpp"  

namespace CommonLib {

  class NiPlane
  {
    public:
      NiPlane();
      ~NiPlane();

      NiPoint3 m_kNormal;
      float m_fConstant;
  };

  static_assert(sizeof(NiPlane) == 0x10, "NiPlane has wrong size");
  
} // namespace CommonLib
