#pragma once
#include <xmmintrin.h>
#include "Gamebryo/NiPoint3.hpp"
#include "Havok/hkBool.hpp"

namespace CommonLib {

  class hkTransform;
  class hkMatrix3;
  class hkRotation;

  class alignas(16) hkVector4
  {
    public: 
      hkVector4();
      ~hkVector4();
      hkVector4(const hkVector4& aOther);
      hkVector4(const NiPoint3& aPoint);
      hkVector4(float afX, float afY, float afZ, float afW);

      hkBool isOk3() const;
      hkBool isOk4() const;
      hkBool isNormalized3(float eps) const;
      hkBool isNormalized4(float eps) const;
      void setAbs3(const hkVector4& aOther);
      void setAbs4(const hkVector4& aOther);
      void setNeg3(const hkVector4& aOther);
      void setNeg4(const hkVector4& aOther);
      float length3();
      float length4();
      void normalize3();
      void normalize4();
      void setCross3 (const hkVector4& aOther, const hkVector4& bOther);
      static hkVector4 fromPoint (const NiPoint3& aPoint);
      void setTransformedPos(const hkTransform& t, const hkVector4& v);
      void setTransformedInversePos(const hkTransform& t, const hkVector4& v);
      void setMul3(const hkMatrix3& a, const hkVector4& b);
      void setRotatedDir(const hkRotation& t, const hkVector4& v);

      hkVector4 operator+ (const hkVector4& aOther) const;
      hkVector4& operator+= (const hkVector4& aOther);
      hkVector4 operator+ (float afVal) const;
      hkVector4& operator+= (float afVal);
      hkVector4 operator- (const hkVector4& aOther) const;
      hkVector4& operator-= (const hkVector4& aOther);
      hkVector4 operator- (float afVal) const;
      hkVector4& operator-= (float afVal);
      hkVector4 operator* (const hkVector4& aOther) const;
      hkVector4& operator*= (const hkVector4& aOther);
      hkVector4 operator* (float afVal) const;
      hkVector4& operator*= (float afVal);
      hkVector4 operator/ (const hkVector4& aOther) const;
      hkVector4& operator/= (const hkVector4& aOther);
      hkVector4 operator/ (float afVal) const;
      hkVector4& operator/= (float afVal);

      __m128 m_quad;
  };

  static_assert(sizeof(hkVector4) == 0x10, "hkVector4 has wrong size");
  
} // namespace CommonLib
