#include <cmath>
#include "Gamebryo/NiMatrix3.hpp"
#include "Gamebryo/Constants.hpp"

namespace CommonLib {

  NiMatrix3::NiMatrix3() : m_pEntry{NiPoint3::ZERO, NiPoint3::ZERO, NiPoint3::ZERO} {};

  NiMatrix3::~NiMatrix3() = default;

  NiMatrix3::NiMatrix3(const NiPoint3& row1, const NiPoint3& row2, const NiPoint3& row3) 
    : m_pEntry{row1, row2, row3} {};

  void NiMatrix3::ToEulerAnglesZXY(float &rfZAngle, float &rfXAngle, float &rfYAngle) const {
    float fM11 = m_pEntry[1].y;
    float fTemp1;
    float fTemp2;

    if (fM11 <= -1.0f) {
      fTemp1 = NI_HALF_PI_696;
      fTemp2 = -NI_HALF_PI_696;
    } else if (fM11 >= 1.0f) {
      fTemp1 = NI_HALF_PI_696;
      fTemp2 = NI_HALF_PI_696;
    } else {
      fTemp1 = NI_HALF_PI_696;
      fTemp2 = std::asin(fM11);
    }

    rfXAngle = -fTemp2;

    if (-fTemp2 >= fTemp1) {
      rfYAngle = 0.0f;
      rfZAngle = -std::atan2(m_pEntry[0].z, m_pEntry[0].x);
    } else if (-fTemp1 >= -fTemp2) {
      rfYAngle = 0.0f;
      rfZAngle = std::atan2(m_pEntry[0].z, m_pEntry[0].x);
    } else {
      rfZAngle = -std::atan2(-m_pEntry[0].y, m_pEntry[1].y);
      rfYAngle = -std::atan2(-m_pEntry[2].x, m_pEntry[2].z);
    }
  }

  void NiMatrix3::FromEulerAnglesZXY(float rfZAngle, float rfXAngle, float rfYAngle) {
    float fSinX = std::sin(rfXAngle);
    float fSinY = std::sin(rfYAngle);
    float fSinZ = std::sin(rfZAngle);
    float fCosX = std::cos(rfXAngle);
    float fCosY = std::cos(rfYAngle);
    float fCosZ = std::cos(rfZAngle);

    NiMatrix3 xRot {
      NiPoint3::UNIT_X,
      NiPoint3{0.0f, fCosX, fSinX},
      NiPoint3{0.0f, -fSinX, fCosX}
    };
    NiMatrix3 yRot {
      NiPoint3{fCosY, 0.0f, -fSinY},
      NiPoint3::UNIT_Y,
      NiPoint3{0.0f, fSinY, fCosY}
    };
    NiMatrix3 zRot {
      NiPoint3{fCosZ, fSinZ, 0.0f},
      NiPoint3{-fSinZ, fCosZ, 0.0f},
      NiPoint3::UNIT_Z
    };
  }

  NiMatrix3& NiMatrix3::Multiply(NiMatrix3 &result, const NiMatrix3 &mat) const {
    NiMatrix3 temp{};

    temp.m_pEntry[0].x = m_pEntry[0].x * mat.m_pEntry[0].x
                        + m_pEntry[0].y * mat.m_pEntry[1].x
                        + m_pEntry[0].z * mat.m_pEntry[2].x;

    temp.m_pEntry[1].x = m_pEntry[1].x * mat.m_pEntry[0].x
                        + m_pEntry[1].y * mat.m_pEntry[1].x
                        + m_pEntry[1].z * mat.m_pEntry[2].x;

    temp.m_pEntry[2].x = m_pEntry[2].x * mat.m_pEntry[0].x
                        + m_pEntry[2].y * mat.m_pEntry[1].x
                        + m_pEntry[2].z * mat.m_pEntry[2].x;

    temp.m_pEntry[0].y = m_pEntry[0].x * mat.m_pEntry[0].y
                        + m_pEntry[0].y * mat.m_pEntry[1].y
                        + m_pEntry[0].z * mat.m_pEntry[2].y;

    temp.m_pEntry[1].y = m_pEntry[1].x * mat.m_pEntry[0].y
                        + m_pEntry[1].y * mat.m_pEntry[1].y
                        + m_pEntry[1].z * mat.m_pEntry[2].y;

    temp.m_pEntry[2].y = m_pEntry[2].x * mat.m_pEntry[0].y
                        + m_pEntry[2].y * mat.m_pEntry[1].y
                        + m_pEntry[2].z * mat.m_pEntry[2].y;

    temp.m_pEntry[0].z = m_pEntry[0].x * mat.m_pEntry[0].z
                        + m_pEntry[0].y * mat.m_pEntry[1].z
                        + m_pEntry[0].z * mat.m_pEntry[2].z;

    temp.m_pEntry[1].z = m_pEntry[1].x * mat.m_pEntry[0].z
                        + m_pEntry[1].y * mat.m_pEntry[1].z
                        + m_pEntry[1].z * mat.m_pEntry[2].z;

    temp.m_pEntry[2].z = m_pEntry[2].x * mat.m_pEntry[0].z
                        + m_pEntry[2].y * mat.m_pEntry[1].z
                        + m_pEntry[2].z * mat.m_pEntry[2].z;

    result = temp;
    return result;
  }

  const NiMatrix3 NiMatrix3::ZERO = NiMatrix3(NiPoint3::ZERO, NiPoint3::ZERO, NiPoint3::ZERO);
  const NiMatrix3 NiMatrix3::IDENTITY = NiMatrix3(NiPoint3::UNIT_X, NiPoint3::UNIT_Y, NiPoint3::UNIT_Z);

} // namespace CommonLib
