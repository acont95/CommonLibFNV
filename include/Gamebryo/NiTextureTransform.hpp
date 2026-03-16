#pragma once
#include <cstdint>
#include "Gamebryo/NiPoint2.hpp"
#include "Gamebryo/NiMatrix3.hpp"
#include "Gamebryo/NiMemObject.hpp"

namespace CommonLib {

  class NiTextureTransform : public NiMemObject
  {
    public:
      NiTextureTransform();
      ~NiTextureTransform();

      enum TransformMethod
      {
        MAYA_DEPRECATED_TRANSFORM = 0x0,
        MAX_TRANSFORM = 0x1,
        MAYA_TRANSFORM = 0x2,
      };

      NiPoint2 m_kTranslate;
      float m_fRotate;
      NiPoint2 m_kScale;
      NiPoint2 m_kCenter;
      bool m_bMatrixDirty;
      NiMatrix3 m_kMatrix;
      NiTextureTransform::TransformMethod m_eMethod;
  };

  static_assert(sizeof(NiTextureTransform) == 0x48, "NiTextureTransform has wrong size");
  
} // namespace CommonLib
