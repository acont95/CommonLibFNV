#include <cmath>
#include <limits>
#include "Gamebryo/NiPoint3.hpp"

namespace CommonLib {

  NiPoint3::NiPoint3() : x(0.0f), y(0.0f), z(0.0f) {}

  NiPoint3::~NiPoint3() = default;

  NiPoint3::NiPoint3(float afX, float afY, float afZ) : x(afX), y(afY), z(afZ){}

  float NiPoint3::SumSquares() const {
    return x*x + y*y + z*z;
  }

  float NiPoint3::Length() const {
    return std::sqrt(x*x + y*y + z*z);
  }

  void NiPoint3::Unitize() {
    float length = Length();
    if (length <= 0.000001f) {
      x = 0.0f;
      y = 0.0f;
      z = 0.0f;
    } else {
      float inverseLength = 1.0f / length;
      x *= inverseLength;
      y *= inverseLength;
      z *= inverseLength;
    }
  }

  float NiPoint3::UnitizeGetLength() {
    float length = Length();
    if (length <= 0.000001f) {
      x = 0.0f;
      y = 0.0f;
      z = 0.0f;
    } else {
      float inverseLength = 1.0f / length;
      x *= inverseLength;
      y *= inverseLength;
      z *= inverseLength;
    }

    return length;
  }

  void NiPoint3::Add(NiPoint3& aPoint) {
    x += aPoint.x;
    y += aPoint.y;
    z += aPoint.z;
  }

  NiPoint3& NiPoint3::AddInto(NiPoint3& result, NiPoint3& aPoint) const {
    float fX = x + aPoint.x;
    float fY = y + aPoint.y;
    float fZ = z + aPoint.z;

    NiPoint3 pointOut {fX, fY, fZ};
    result = pointOut;
    return result;
  }

  void NiPoint3::Subtract(NiPoint3& aPoint) {
    x -= aPoint.x;
    y -= aPoint.y;
    z -= aPoint.z;
  }

  NiPoint3& NiPoint3::SubtractInto(NiPoint3& result, NiPoint3& aPoint) const {
    float fX = x - aPoint.x;
    float fY = y - aPoint.y;
    float fZ = z - aPoint.z;

    NiPoint3 pointOut {fX, fY, fZ};
    result = pointOut;
    return result;
  }

  void NiPoint3::Mult(NiPoint3& aPoint) {
    x *= aPoint.x;
    y *= aPoint.y;
    z *= aPoint.z;
  }

  NiPoint3& NiPoint3::MultInto(NiPoint3& result, NiPoint3& aPoint) const {
    float fX = x * aPoint.x;
    float fY = y * aPoint.y;
    float fZ = z * aPoint.z;

    NiPoint3 pointOut {fX, fY, fZ};
    result = pointOut;
    return result;
  }

  NiPoint3& NiPoint3::MultInverseInto(NiPoint3& result, float afValue) const {
    float fInverseValue = 1.0f / afValue;
    float fX = x * fInverseValue;
    float fY = y * fInverseValue;
    float fZ = z * fInverseValue;

    NiPoint3 pointOut {fX, fY, fZ};
    result = pointOut;
    return result;
  }

  void NiPoint3::Divide(NiPoint3& aPoint) {
    x /= aPoint.x;
    y /= aPoint.y;
    z /= aPoint.z;
  }

  NiPoint3& NiPoint3::DivideInto(NiPoint3& result, NiPoint3& aPoint) const {
    float fX = x / aPoint.x;
    float fY = y / aPoint.y;
    float fZ = z / aPoint.z;

    NiPoint3 pointOut {fX, fY, fZ};
    result = pointOut;
    return result;
  }

  NiPoint3& NiPoint3::UnitCross(NiPoint3& result, const NiPoint3& pt) {
    float fYZ = (this->y * pt.z) - (this->z * pt.y);
    float fXZ = (this->z * pt.x) - (this->x * pt.z);
    float fXY = (this->x * pt.y) - (this->y * pt.x);

    NiPoint3 newPoint {fYZ, fXZ, fXY};
    float length = newPoint.Length();
    if (length <= 0.000001f) {
      result.x = 0.0f;
      result.y = 0.0f;
      result.z = 0.0f;
    } else {
      newPoint.MultInverseInto(result, length);
    }
    return result;
  }

  NiPoint3& NiPoint3::Perpendicular(NiPoint3& result) {
    float fAbsX = std::abs(x);
    float fAbsY = std::abs(y);
    float fAbsZ = std::abs(z);
    if (fAbsY <= fAbsX) {
      if (fAbsY <= fAbsZ) {
        UnitCross(result, UNIT_Y);
      } else {
        UnitCross(result, UNIT_Z);
      }
    } else {
      if (fAbsX <= fAbsZ) {
        UnitCross(result, UNIT_X);
      } else {
        UnitCross(result, UNIT_Z);
      }
    }
    return result;
  }

  const NiPoint3 NiPoint3::ZERO = NiPoint3(0.0f, 0.0f, 0.0f);
  const NiPoint3 NiPoint3::UNIT_X = NiPoint3(1.0f, 0.0f, 0.0f);
  const NiPoint3 NiPoint3::UNIT_Y = NiPoint3(0.0f, 1.0f, 0.0f);
  const NiPoint3 NiPoint3::UNIT_Z = NiPoint3(0.0f, 0.0f, 1.0f);
  const NiPoint3 NiPoint3::UNIT_ALL = NiPoint3(1.0f, 1.0f, 1.0f);
  const NiPoint3 NiPoint3::INFINITY_POINT3 = NiPoint3(
    std::numeric_limits<float>::infinity(), 
    std::numeric_limits<float>::infinity(), 
    std::numeric_limits<float>::infinity());

} // namespace CommonLib
