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
      void Add(NiPoint3& aPoint);
      NiPoint3 AddInto(NiPoint3& aPoint) const;
      void Subtract(NiPoint3& aPoint);
      NiPoint3 SubtractInto(NiPoint3& aPoint) const;
      void Mult(NiPoint3& aPoint);
      NiPoint3 MultInto(NiPoint3& aPoint) const;
      void MultInverse(NiPoint3& aPoint);
      NiPoint3 MultInverseInto(float afValue) const;
      void Divide(NiPoint3& aPoint);
      NiPoint3 DivideInto(NiPoint3& aPoint) const;
      NiPoint3 UnitCross(const NiPoint3& pt) const;
      NiPoint3 Perpendicular() const;

      static const NiPoint3 ZERO;
      static const NiPoint3 UNIT_X;
      static const NiPoint3 UNIT_Y;
      static const NiPoint3 UNIT_Z;
      static const NiPoint3 UNIT_ALL;
      static const NiPoint3 INFINITY_POINT3;
  };

  static_assert(sizeof(NiPoint3) == 0xC, "NiPoint3 has wrong size");
  
} // namespace CommonLib
