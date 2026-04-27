#pragma once
#include <cstdint>
#include "Bethesda/TESBoundAnimObject.hpp"
#include "Bethesda/TESSoundFile.hpp"

namespace CommonLib {

  class TESSound : public TESBoundAnimObject, public TESSoundFile
  {
    public:

      struct SOUND_DATA
      {
        std::uint8_t iMin;
        std::uint8_t iMax;
        char iPitch;
        std::uint8_t iPadding1;
        std::uint32_t iFlags;
        std::uint16_t iAttenuation;
        std::uint16_t iTimeConstraints;
        std::uint16_t pAttenuationCurve[5];
        std::uint16_t iReverbAttenuation;
        std::uint32_t iPriority;
        std::uint32_t iLoopBegin;
        std::uint32_t iLoopEnd;
      };

      BSStringT<char> cFormEditorID;
      SOUND_DATA data;
      char cRandomPercentChance;
      std::uint8_t pad01[3];
  };

  static_assert(sizeof(TESSound) == 0x6C, "TESSound has wrong size");
  
} // namespace CommonLib
