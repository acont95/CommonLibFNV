#pragma once
#include "Bethesda/Actor.hpp"

namespace CommonLib {

  template <typename T>
  class BSSimpleList;
  class ItemChange;

  class InventoryChanges
  {
    public:

      BSSimpleList<ItemChange *> *pListofChanges;
      TESObjectREFR *pRef;
      float fcontainerweight;
      float fpreviousContainerWeight;
      bool bcountdirty;
  };

  static_assert(sizeof(InventoryChanges) == 0x14, "InventoryChanges has wrong size");
  
} // namespace CommonLib
