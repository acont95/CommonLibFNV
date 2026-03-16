#pragma once
#include "Gamebryo/NiNPShortPoint3.hpp"
#include "Bethesda/TESObject.hpp"

namespace CommonLib {

  class TESBoundObject : public TESObject
  {
    public:
      TESBoundObject();
      virtual ~TESBoundObject();

      struct BOUND_DATA
      {
        NiNPShortPoint3 BoundMin;
        NiNPShortPoint3 BoundMax;
      };

      BOUND_DATA BoundData;
  };

  static_assert(sizeof(TESBoundObject) == 0x30, "TESBoundObject has wrong size");
  
} // namespace CommonLib
