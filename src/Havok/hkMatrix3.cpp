#include "Havok/hkMatrix3.hpp"

namespace CommonLib
{
  hkMatrix3::hkMatrix3()
      : m_col0{}, m_col1{}, m_col2{} {};

  hkMatrix3::hkMatrix3(hkVector4& col0, hkVector4& col1, hkVector4& col2)
      : m_col0(col0), m_col1(col1), m_col2(col2) {};

  void hkMatrix3::transpose() {
    float fM12 = this->m_col1.m_quad.m128_f32[0];
    this->m_col1.m_quad.m128_f32[0] = this->m_col0.m_quad.m128_f32[1];
    this->m_col0.m_quad.m128_f32[1] = fM12;
    float fM13 = this->m_col2.m_quad.m128_f32[0];
    this->m_col2.m_quad.m128_f32[0] = this->m_col0.m_quad.m128_f32[2];
    this->m_col0.m_quad.m128_f32[2] = fM13;
    float fM23 = this->m_col2.m_quad.m128_f32[1];
    this->m_col2.m_quad.m128_f32[1] = this->m_col1.m_quad.m128_f32[2];
    this->m_col1.m_quad.m128_f32[2] = fM23;
  }

  void hkMatrix3::setTranspose(const hkMatrix3& s) {
    this->m_col0.m_quad.m128_f32[0] = s.m_col0.m_quad.m128_f32[0];
    this->m_col1.m_quad.m128_f32[1] = s.m_col1.m_quad.m128_f32[1];
    this->m_col2.m_quad.m128_f32[2] = s.m_col2.m_quad.m128_f32[2];
    this->m_col0.m_quad.m128_f32[3] = 0.0;
    this->m_col1.m_quad.m128_f32[3] = 0.0;
    this->m_col2.m_quad.m128_f32[3] = 0.0;
    this->m_col0.m_quad.m128_f32[1] = s.m_col1.m_quad.m128_f32[0];
    this->m_col1.m_quad.m128_f32[0] = s.m_col0.m_quad.m128_f32[1];
    this->m_col0.m_quad.m128_f32[2] = s.m_col2.m_quad.m128_f32[0];
    this->m_col2.m_quad.m128_f32[0] = s.m_col0.m_quad.m128_f32[2];
    this->m_col1.m_quad.m128_f32[2] = s.m_col2.m_quad.m128_f32[1];
    this->m_col2.m_quad.m128_f32[1] = s.m_col1.m_quad.m128_f32[2];
  }
}
