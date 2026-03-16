#pragma once
#include "Bethesda/TESBoundObject.hpp"

namespace CommonLib {

  class TESBoundAnimObject : public TESBoundObject
  {
    public:
      TESBoundAnimObject();
      ~TESBoundAnimObject();
  };

  static_assert(sizeof(TESBoundAnimObject) == 0x30, "TESBoundAnimObject has wrong size");
  
} // namespace CommonLib
