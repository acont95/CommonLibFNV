#pragma once

namespace CommonLib {

  class TESObjectCELL;

  class TESChildCell
  {
    public:
      virtual TESObjectCELL* GetSaveParentCell(TESChildCell *);
  };

  static_assert(sizeof(TESChildCell) == 0x4, "TESChildCell has wrong size");
  
} // namespace CommonLib
