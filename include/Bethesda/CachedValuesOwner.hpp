#pragma once

namespace CommonLib {

  class CachedValuesOwner
  {
    public:
      virtual ~CachedValuesOwner();
  };

  static_assert(sizeof(CachedValuesOwner) == 0x4, "CachedValuesOwner has wrong size");
  
} // namespace CommonLib
