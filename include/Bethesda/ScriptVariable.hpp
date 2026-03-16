#pragma once
#include "Bethesda/BSStringT.hpp"
#include "Types.hpp"

namespace CommonLib {

  class ScriptVariable
  {
    public:
      ScriptVariable();
      ~ScriptVariable();

      SCRIPT_LOCAL data;
      BSStringT<char> cName;
  };

  static_assert(sizeof(ScriptVariable) == 0x20);
  
} // namespace CommonLib
