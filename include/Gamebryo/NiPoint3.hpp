#pragma once

namespace CommonLib {

  class NiPoint3
  {
    public:
      float x;
      float y;
      float z;

      NiPoint3();
      ~NiPoint3();
      NiPoint3(float afX, float afY, float afZ);
      float SumSquares() const;
      float Length() const;
      void Unitize();
      float UnitizeGetLength(); 
      void NiPoint3::Add(NiPoint3& aPoint);
      NiPoint3& NiPoint3::AddInto(NiPoint3& result, NiPoint3& aPoint) const;
      void NiPoint3::Subtract(NiPoint3& aPoint);
      NiPoint3& NiPoint3::SubtractInto(NiPoint3& result, NiPoint3& aPoint) const;
      void NiPoint3::Mult(NiPoint3& aPoint);
      NiPoint3& NiPoint3::MultInto(NiPoint3& result, NiPoint3& aPoint) const;
      NiPoint3& NiPoint3::MultInverseInto(NiPoint3& result, float afValue) const;
      void NiPoint3::Divide(NiPoint3& aPoint);
      NiPoint3& NiPoint3::DivideInto(NiPoint3& result, NiPoint3& aPoint) const;
      NiPoint3& NiPoint3::UnitCross(NiPoint3& result, const NiPoint3& pt);
      NiPoint3& NiPoint3::Perpendicular(NiPoint3& result);

      static const NiPoint3 ZERO;
      static const NiPoint3 UNIT_X;
      static const NiPoint3 UNIT_Y;
      static const NiPoint3 UNIT_Z;
      static const NiPoint3 UNIT_ALL;
      static const NiPoint3 INFINITY_POINT3;
  };

  static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 has wrong size");
  
} // namespace CommonLib
