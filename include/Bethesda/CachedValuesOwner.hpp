#pragma once

namespace CommonLib {

  class CachedValuesOwner
  {
    public:
      CachedValuesOwner();
      virtual ~CachedValuesOwner();
  };

  static_assert(sizeof(CachedValuesOwner) == 0x4, "CachedValuesOwner has wrong size");
  
} // namespace CommonLib
