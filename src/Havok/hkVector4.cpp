#include "Havok/hkVector4.hpp"
#include <xmmintrin.h>
#include <pmmintrin.h>
#include <cmath>

namespace CommonLib
{
  hkVector4::hkVector4()
      : m_quad(_mm_setzero_ps()) {}

  hkVector4::hkVector4(const hkVector4& aOther)
      : m_quad(aOther.m_quad) {}

  hkVector4::hkVector4(const NiPoint3& aPoint)
      : m_quad(_mm_set_ps(0.0f, aPoint.z, aPoint.y, aPoint.x)) {}

  hkVector4::hkVector4(float afX, float afY, float afZ, float afW)
      : m_quad(_mm_set_ps(afW, afZ, afY, afX)) {}

  hkBool hkVector4::isOk3() const {
    return hkBool{ std::isfinite(this->m_quad.m128_f32[0]) &&
           std::isfinite(this->m_quad.m128_f32[1]) &&
           std::isfinite(this->m_quad.m128_f32[2]) };
  }

  hkBool hkVector4::isOk4() const {
    return hkBool{ std::isfinite(this->m_quad.m128_f32[0]) &&
           std::isfinite(this->m_quad.m128_f32[1]) &&
           std::isfinite(this->m_quad.m128_f32[2]) &&
           std::isfinite(this->m_quad.m128_f32[3]) };
  }

  hkBool hkVector4::isNormalized3(float eps) const {
    hkBool result { false };
    if (!this->isOk3().m_bool) return result;
    __m128 thisVec = this->m_quad;
    __m128 vecSquared = _mm_mul_ps(thisVec, thisVec);
    // x + y
    __m128 t1 = _mm_add_ss(vecSquared, _mm_shuffle_ps(vecSquared, vecSquared, _MM_SHUFFLE(0,0,0,1)));
    // (x+y) + z
    __m128 t2 = _mm_add_ss(t1, _mm_shuffle_ps(vecSquared, vecSquared, _MM_SHUFFLE(0,0,0,2)));
    float sum = _mm_cvtss_f32(t2);

    if (std::abs(1.0f - sum) < eps) {
      result.m_bool = true;
    }

    return result;
  }

  hkBool hkVector4::isNormalized4(float eps) const {
    hkBool result { false };
    if (!this->isOk4().m_bool) return result;
    __m128 thisVec = this->m_quad;
    __m128 vecSquared = _mm_mul_ps(thisVec, thisVec);

    __m128 t = _mm_hadd_ps(thisVec, thisVec);
    t = _mm_hadd_ps(t, t);
    float sum = _mm_cvtss_f32(t);

    if (std::abs(1.0f - sum) < eps) {
      result.m_bool = true;
    }

    return result;
  }

  hkVector4& hkVector4::setAbs3(const hkVector4& aOther)
  {
    const __m128 mask = _mm_castsi128_ps(_mm_set_epi32(0x00000000, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF));
    m_quad = _mm_and_ps(aOther.m_quad, mask);

    return *this;
  }

  hkVector4& hkVector4::setAbs4(const hkVector4& aOther)
  {
    m_quad = _mm_and_ps(aOther.m_quad, _mm_castsi128_ps(_mm_set1_epi32(0x7FFFFFFF)));
    return *this;
  }
}
