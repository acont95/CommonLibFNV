#pragma once
#include <cstdint>

namespace CommonLib {

  class BSExtraData;

  class BaseExtraList {
    public:
      virtual ~BaseExtraList();

      BSExtraData* pHead;
      std::uint8_t iFlags[21];
  };

  static_assert(sizeof(BaseExtraList) == 0x20, "BaseExtraList has wrong size");
  
} // namespace CommonLib
