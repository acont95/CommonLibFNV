#pragma once

namespace CommonLib {

  template <typename T>
  class BSSimpleList;
  class ExtraDataList;
  class TESBoundObject;

  class ItemChange {
    public:
      ItemChange();
      ~ItemChange();

      enum StatusFlags
      {
        SF_STOLEN = 0x1,
        SF_ENCHANTED = 0x2,
        SF_POISONED = 0x4,
        SF_BROKEN = 0x8,
      };

      BSSimpleList<ExtraDataList *> *pExtraObjectList;
      int iNumber;
      TESBoundObject *pContainerObj;
  };

  static_assert(sizeof(ItemChange) == 0xC, "ItemChange has wrong size");
  
} // namespace CommonLib
