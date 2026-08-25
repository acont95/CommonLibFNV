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

      std::uint8_t cSectionPriority[8];
      std::uint16_t sType;
      unsigned int frameCount;
      float *times;
      NiPoint3 speed;
      char cMorphKey;
      std::uint8_t cBlendFrames;
      std::uint8_t cBlendInFrames;
      std::uint8_t cBlendOutFrames;
      std::uint8_t cDecal;
      const char *pParentName;
      unsigned int soundCount;
      GROUP_SOUND *sounds;
  };

  static_assert(sizeof(TESAnimGroup) == 0x3C, "TESAnimGroup has wrong size");
  
} // namespace CommonLib
