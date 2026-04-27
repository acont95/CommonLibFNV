#include "Havok/hkVector4.hpp"
#include "Havok/constants.hpp"
#include "Havok/hkTransform.hpp"
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

  void hkVector4::setAbs3(const hkVector4& aOther)
  {
    const __m128 mask = _mm_castsi128_ps(_mm_set_epi32(0xFFFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF, 0x7FFFFFFF));
    m_quad = _mm_and_ps(aOther.m_quad, mask);
  }

  void hkVector4::setAbs4(const hkVector4& aOther)
  {
    m_quad = _mm_and_ps(aOther.m_quad, _mm_castsi128_ps(_mm_set1_epi32(0x7FFFFFFF)));
  }

  void hkVector4::setNeg3(const hkVector4& aOther)
  {
    const __m128 mask = _mm_castsi128_ps(_mm_set_epi32(0x00000000, 0x80000000, 0x80000000, 0x80000000));
    m_quad = _mm_xor_ps(aOther.m_quad, mask);
  }

  void hkVector4::setNeg4(const hkVector4& aOther)
  {
    m_quad = _mm_xor_ps(aOther.m_quad, _mm_castsi128_ps(_mm_set1_epi32(0x80000000)));
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
    if (length > 0.000001f) {
      __m128 inv = _mm_set1_ps(1.0f / length);
      __m128 scaled = _mm_mul_ps(m_quad, inv);

      m_quad = _mm_or_ps(
          _mm_and_ps(scaled, _mm_castsi128_ps(_mm_set_epi32(0, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF))),
          _mm_and_ps(m_quad, _mm_castsi128_ps(_mm_set_epi32(0xFFFFFFFF, 0, 0, 0)))
      );
    } else {
      m_quad = _mm_and_ps(m_quad, _mm_castsi128_ps(_mm_set_epi32(0xFFFFFFFF, 0, 0, 0)));
    }
  }

  void hkVector4::normalize4() {
    __m128 thisVec = this->m_quad;
    float length = this->length4();
    if (length > 0.000001f) {
      __m128 inv = _mm_set1_ps(1.0f / length);
      m_quad = _mm_mul_ps(thisVec, inv);
    } else {
      m_quad = _mm_setzero_ps();
    }
  }

  void hkVector4::setCross3(const hkVector4& aOther, const hkVector4& bOther) {
    __m128 a = aOther.m_quad;
    __m128 b = bOther.m_quad;

    __m128 a_yzx = _mm_shuffle_ps(a, a, _MM_SHUFFLE(3,0,2,1));
    __m128 b_yzx = _mm_shuffle_ps(b, b, _MM_SHUFFLE(3,0,2,1));

    __m128 c = _mm_sub_ps(
        _mm_mul_ps(a, b_yzx),
        _mm_mul_ps(b, a_yzx)
    );

    __m128 result_xyz = _mm_shuffle_ps(c, c, _MM_SHUFFLE(3,0,2,1));
    __m128 maskW = _mm_castsi128_ps(_mm_set_epi32(0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000));

    __m128 w = _mm_and_ps(a, maskW);
    m_quad = _mm_or_ps(result_xyz, w);
  }

  hkVector4 hkVector4::fromPoint(const NiPoint3& aPoint) {
    hkVector4 result{};
    result.m_quad = _mm_set_ps(0.0f, aPoint.z*fBS2HkScaleSC_639, aPoint.y*fBS2HkScaleSC_639, aPoint.x*fBS2HkScaleSC_639);
    return result;
  }

  void hkVector4::setTransformedPos(const hkTransform& t, const hkVector4& v) {
    m_quad = _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v.m_quad, v.m_quad, 85), t.m_rotation.m_col1.m_quad),
                _mm_mul_ps(_mm_shuffle_ps(v.m_quad, v.m_quad, 0), t.m_rotation.m_col0.m_quad)),
              _mm_add_ps(
                _mm_mul_ps(_mm_shuffle_ps(v.m_quad, v.m_quad, 170), t.m_rotation.m_col2.m_quad),
                t.m_translation.m_quad));
  }

  void hkVector4::setTransformedInversePos(const hkTransform& t, const hkVector4& v) {
    __m128 m_col1 = t.m_rotation.m_col1.m_quad;
    __m128 m_col2 = t.m_rotation.m_col2.m_quad;

    __m128 t1 = _mm_sub_ps(v.m_quad, t.m_translation.m_quad);
    __m128 t2 = _mm_unpacklo_ps(t.m_rotation.m_col0.m_quad, m_col1);
    __m128 t3 = _mm_movelh_ps(t2, m_col2);
    m_quad = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(
                    _mm_shuffle_ps(t1, t1, 85),
                    _mm_shuffle_ps(_mm_movehl_ps(t3, t2), m_col2, 212)),
                  _mm_mul_ps(_mm_shuffle_ps(t1, t1, 0), t3)),
                _mm_mul_ps(
                  _mm_shuffle_ps(
                    _mm_unpackhi_ps(t.m_rotation.m_col0.m_quad, m_col1),
                    m_col2,
                    228),
                  _mm_shuffle_ps(t1, t1, 170)));
  }

  void hkVector4::setMul3(const hkMatrix3& a, const hkVector4& b) {
    m_quad = _mm_add_ps(
                _mm_add_ps(
                  _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 85), a.m_col1.m_quad),
                  _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 0), a.m_col0.m_quad)),
                _mm_mul_ps(_mm_shuffle_ps(b.m_quad, b.m_quad, 170), a.m_col2.m_quad));
  }

  void hkVector4::setRotatedDir(const hkRotation& t, const hkVector4& v) {
    m_quad = _mm_add_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_shuffle_ps(v.m_quad, v.m_quad, 85), t.m_col1.m_quad),
                          _mm_mul_ps(_mm_shuffle_ps(v.m_quad, v.m_quad, 0), t.m_col0.m_quad)),
                        _mm_mul_ps(_mm_shuffle_ps(v.m_quad, v.m_quad, 170), t.m_col2.m_quad));
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
    hkVector4 result{};
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
}
