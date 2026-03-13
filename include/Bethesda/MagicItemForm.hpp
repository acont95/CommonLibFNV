#pragma once
#include "Bethesda/TESForm.hpp"
#include "Bethesda/MagicItem.hpp"
#include "Bethesda/MagicSystem.hpp"

class MagicItemForm : TESForm, MagicItem {
  public:
    MagicItemForm();
    ~MagicItemForm();
};

static_assert(sizeof(MagicItemForm) == 0x34, "MagicItemForm has wrong size");
