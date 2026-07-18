#pragma once
#include <cstdint>
#include "Bethesda/BaseFormComponent.hpp"
#include "Gamebryo/NiPoint3.hpp"
#include "Gamebryo/NiRefObject.hpp"

namespace CommonLib {

  class GROUP_SOUND;

  class TESAnimGroup : public NiRefObject
  {
    public:
      TESAnimGroup();
      virtual ~TESAnimGroup();

      unsigned __int8 cSectionPriority[8];
      unsigned __int16 sType;
      unsigned int frameCount;
      float *times;
      NiPoint3 speed;
      char cMorphKey;
      unsigned __int8 cBlendFrames;
      unsigned __int8 cBlendInFrames;
      unsigned __int8 cBlendOutFrames;
      unsigned __int8 cDecal;
      const char *pParentName;
      unsigned int soundCount;
      GROUP_SOUND *sounds;
  };

  static_assert(sizeof(TESAnimGroup) == 0x3C, "TESAnimGroup has wrong size");
  
} // namespace CommonLib
