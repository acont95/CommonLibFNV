#pragma once

namespace CommonLib {

  class TESChildCell
  {
    public:
      virtual ~TESChildCell();
  };

  static_assert(sizeof(TESChildCell) == 0x4, "TESChildCell has wrong size");
  
} // namespace CommonLib
