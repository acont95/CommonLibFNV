#pragma once
#include "Gamebryo/NiFogProperty.hpp"
#include "Gamebryo/NiPlane.hpp"

namespace CommonLib {

  class BSFogProperty : public NiFogProperty
  {
    public:
      BSFogProperty();
      virtual ~BSFogProperty();

      float fStartDistance;
      float fEndDistance;
      float fStartWaterDistance;
      float fEndWaterDistance;
      NiPlane kPlane;
      float fFalloff;
      float fHeight;
      NiColor kWaterColor;
      float fPower;
  };

  static_assert(sizeof(BSFogProperty) == 0x64, "BSFogProperty has wrong size");

} // namespace CommonLib
