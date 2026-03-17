#pragma once
#include "Bethesda/BSSimpleList.hpp"

// TODO
namespace CommonLib {

  class FastModifierCollection;
  class Modifier;

  class ModifierList : public BSSimpleList<Modifier *>
  {
    public:
      ModifierList();
      ~ModifierList();

      bool bZeroValuesAllowed;
      FastModifierCollection *pFastModifiers;
  };

  static_assert(sizeof(ModifierList) == 0x10, "ModifierList has wrong size");
  
} // namespace CommonLib
