#pragma once
#include "Bethesda/BaseFormComponent.hpp"
#include "Bethesda/BSStringT.hpp"

namespace CommonLib {

  class TESFullName : public BaseFormComponent {
    public:

      BSStringT<char> cFullName;
  };

  static_assert(sizeof(TESFullName) == 0xC, "TESFullName has wrong size");
  
} // namespace CommonLib
