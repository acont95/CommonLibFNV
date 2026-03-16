#pragma once
#include <cstdint>

namespace CommonLib {

  class TESHealthForm
  {
    public:
      TESHealthForm();
      virtual ~TESHealthForm();

      std::uint32_t iHealth;
  };

  static_assert(sizeof(TESHealthForm) == 0x8, "TESHealthForm has wrong size");
  
} // namespace CommonLib
