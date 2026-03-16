#pragma once
#include <cstdint>

namespace CommonLib {

  class TESValueForm
  {
    public:
      TESValueForm();
      virtual ~TESValueForm();

      std::uint32_t iValue;
  };

  static_assert(sizeof(TESValueForm) == 0x8, "TESValueForm has wrong size");
  
} // namespace CommonLib
