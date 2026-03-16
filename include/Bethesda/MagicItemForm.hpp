#pragma once
#include "Bethesda/TESForm.hpp"
#include "Bethesda/MagicItem.hpp"

class MagicItemForm : public TESForm, public MagicItem {
  public:
    MagicItemForm();
    ~MagicItemForm();
};

static_assert(sizeof(MagicItemForm) == 0x34, "MagicItemForm has wrong size");
