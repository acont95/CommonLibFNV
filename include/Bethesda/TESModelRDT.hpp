#pragma once
#include "Types.hpp"
#include "Bethesda/TESModel.hpp"

namespace CommonLib {

  class TESModelRDT : public TESModel
  {
    public:
      virtual ~TESModelRDT();
  };

  static_assert(sizeof(TESModelRDT) == 0x18, "TESModelRDT has wrong size");
  
} // namespace CommonLib
