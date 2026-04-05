#pragma once
#include "Types.hpp"
#include "Havok/hkVector4.hpp"
#include "Havok/hkpCharacterProxyListener.hpp"

namespace CommonLib {

  class bhkCharacterListener : public hkpCharacterProxyListener
  {
    public:
      bhkCharacterListener();
      virtual ~bhkCharacterListener();

      unsigned int iFlags;
      hkVector4 hkUp;
      float fMaxSlope;
      MATERIAL_TYPE eSupportMaterial;
      COL_LAYER eSupportLayer;
      hkVector4 hkSupportVelocity;
      hkVector4 hkSupportNorm;
      float SupportHeight[4];
      float fStepHeight;
      float fCastDepth;
      bool bAllSurfacesStopped;
      bool bStickyCollisions;
      unsigned int iNumCollisions;
  };

  static_assert(sizeof(bhkCharacterListener) == 0x70, "bhkCharacterListener has wrong size");
  
} // namespace CommonLib
