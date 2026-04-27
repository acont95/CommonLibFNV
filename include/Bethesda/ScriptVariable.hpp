#pragma once
#include "Bethesda/BSStringT.hpp"
#include "Types.hpp"

namespace CommonLib {

  class ScriptVariable
  {
    public:

      SCRIPT_LOCAL data;
      BSStringT<char> cName;
  };

  static_assert(sizeof(ScriptVariable) == 0x20);
  
} // namespace CommonLib
