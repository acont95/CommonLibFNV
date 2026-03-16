#pragma once
#include "Bethesda/BSStringT.hpp"
#include "Bethesda/TESForm.hpp"

class TESGlobal : public TESForm
{
  public:
    TESGlobal();
    ~TESGlobal();

    BSStringT<char> cFormEditorID;
    char cType;
    float fValue;
};

static_assert(sizeof(TESGlobal) == 0x28, "TESGlobal has wrong size");
