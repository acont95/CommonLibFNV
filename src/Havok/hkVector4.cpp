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
    const __m128 mask = _mm_castsi128_ps(_mm_set_epi32(0xFFFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF));
    m_quad = _mm_and_ps(aOther.m_quad, mask);

    return *this;
  }

  hkVector4& hkVector4::setAbs4(const hkVector4& aOther)
  {
    m_quad = _mm_and_ps(aOther.m_quad, _mm_castsi128_ps(_mm_set1_epi32(0x7FFFFFFF)));
    return *this;
  }

  hkVector4& hkVector4::setNeg3(const hkVector4& aOther)
  {
    const __m128 mask = _mm_castsi128_ps(_mm_set_epi32(0x00000000, 0x80000000, 0x80000000, 0x80000000));
    m_quad = _mm_xor_ps(aOther.m_quad, mask);

    return *this;
  }

  hkVector4& hkVector4::setNeg4(const hkVector4& aOther)
  {
    m_quad = _mm_xor_ps(aOther.m_quad, _mm_castsi128_ps(_mm_set1_epi32(0x80000000)));
    return *this;
  }

  float hkVector4::length3() {
    __m128 v = this->m_quad;
    v = _mm_mul_ps(v, v);
    __m128 shuf = _mm_movehdup_ps(v);  // (y,y,w,w)
    __m128 sums = _mm_add_ps(v, shuf);
    shuf = _mm_movehl_ps(shuf, sums);
    sums = _mm_add_ss(sums, shuf);
    return sqrtf(_mm_cvtss_f32(sums));
  }

  float hkVector4::length4() {
    __m128 thisVec = this->m_quad;
    __m128 xmm1 = _mm_mul_ps(thisVec, thisVec);
    __m128 xmm2 = _mm_hadd_ps(xmm1, xmm1);
    __m128 xmm3 = _mm_hadd_ps(xmm2, xmm2);
    return sqrtf(_mm_cvtss_f32(xmm3));
  }

  void hkVector4::normalize3() {
    float length = this->length3();

    __m128 inv = _mm_set1_ps(1.0f / length);

    __m128 scaled = _mm_mul_ps(m_quad, inv);

    m_quad = _mm_or_ps(
        _mm_and_ps(scaled, _mm_castsi128_ps(_mm_set_epi32(0, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF))),
        _mm_and_ps(m_quad, _mm_castsi128_ps(_mm_set_epi32(0xFFFFFFFF, 0, 0, 0)))
    );
  }

  void hkVector4::normalize4() {
    __m128 thisVec = this->m_quad;
    float length = this->length4();
    __m128 inv = _mm_set1_ps(1.0f / length);
    m_quad = _mm_mul_ps(thisVec, inv);
  }

  hkVector4 hkVector4::operator+ (const hkVector4& aOther) const {
    hkVector4 result{};
    result.m_quad = _mm_add_ps(m_quad, aOther.m_quad);
    return result;
  }

  hkVector4& hkVector4::operator+= (const hkVector4& aOther) {
    m_quad = _mm_add_ps(m_quad, aOther.m_quad);
    return *this;
  }

  hkVector4 hkVector4::operator+ (float afVal) const {
    hkVector4 result{};
    __m128 s = _mm_set1_ps(afVal);
    result.m_quad = _mm_add_ps(m_quad, s);
    return result;
  }

  hkVector4& hkVector4::operator+= (float afVal) {
    __m128 s = _mm_set1_ps(afVal);
    m_quad = _mm_add_ps(m_quad, s);
    return *this;
  }

  hkVector4 hkVector4::operator- (const hkVector4& aOther) const {
    hkVector4 result;
    result.m_quad = _mm_sub_ps(m_quad, aOther.m_quad);
    return result;
  }

  hkVector4& hkVector4::operator-= (const hkVector4& aOther) {
    m_quad = _mm_sub_ps(m_quad, aOther.m_quad);
    return *this;
  }

  hkVector4 hkVector4::operator- (float afVal) const {
    hkVector4 result{};
    __m128 s = _mm_set1_ps(-afVal);
    result.m_quad = _mm_add_ps(m_quad, s);
    return result;
  }

  hkVector4& hkVector4::operator-= (float afVal) {
    __m128 s = _mm_set1_ps(-afVal);
    m_quad = _mm_add_ps(m_quad, s);
    return *this;
  }

  hkVector4 hkVector4::operator* (const hkVector4& aOther) const {
    hkVector4 result;
    result.m_quad = _mm_mul_ps(m_quad, aOther.m_quad);
    return result;
  }

  hkVector4& hkVector4::operator*= (const hkVector4& aOther) {
    m_quad = _mm_mul_ps(m_quad, aOther.m_quad);
    return *this;
  }

  hkVector4 hkVector4::operator* (float afVal) const {
    hkVector4 result{};
    __m128 s = _mm_set1_ps(afVal);
    result.m_quad = _mm_mul_ps(m_quad, s);
    return result;
  }

  hkVector4& hkVector4::operator*= (float afVal) {
    __m128 s = _mm_set1_ps(afVal);
    m_quad = _mm_mul_ps(m_quad, s);
    return *this;
  }

  hkVector4 hkVector4::operator/(const hkVector4& aOther) const
  {
    hkVector4 result;
    result.m_quad = _mm_div_ps(m_quad, aOther.m_quad);
    return result;
  }

  hkVector4& hkVector4::operator/=(const hkVector4& aOther)
  {
    m_quad = _mm_div_ps(m_quad, aOther.m_quad);
    return *this;
  }

  hkVector4 hkVector4::operator/(float afVal) const
  {
    hkVector4 result;
    __m128 inv = _mm_set1_ps(1.0f / afVal);
    result.m_quad = _mm_mul_ps(m_quad, inv);
    return result;
  }

  hkVector4& hkVector4::operator/=(float afVal)
  {
    __m128 inv = _mm_set1_ps(1.0f / afVal);
    m_quad = _mm_mul_ps(m_quad, inv);
    return *this;
  }

  hkVector4 hkVector4::cross(const hkVector4& aOther) const {
    __m128 a = m_quad;
    __m128 b = aOther.m_quad;

    __m128 a_yzx = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3,0,2,1));
    __m128 b_yzx = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3,0,2,1));

    __m128 c = _mm_sub_ps(
        _mm_mul_ps(a, b_yzx),
        _mm_mul_ps(b, a_yzx)
    );

    __m128 result_xyz = _mm_shuffle_ps(c, c, _MM_SHUFFLE(3,0,2,1));
    __m128 maskW = _mm_castsi128_ps(_mm_set_epi32(0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000));

    __m128 w = _mm_and_ps(a, maskW);

    hkVector4 result;
    result.m_quad = _mm_or_ps(result_xyz, w);
    return result;
  }
}
