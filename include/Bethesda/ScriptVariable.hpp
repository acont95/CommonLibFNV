#pragma once
#include "Bethesda/BSStringT.hpp"
#include "Types.hpp"

class ScriptVariable
{
  public:
    ScriptVariable();
    ~ScriptVariable();

    SCRIPT_LOCAL data;
    BSStringT<char> cName;
};

static_assert(sizeof(ScriptVariable) == 0x20);
