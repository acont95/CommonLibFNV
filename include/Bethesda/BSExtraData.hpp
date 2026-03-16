#pragma once
#include <cstdint>

namespace CommonLib {

  class BSExtraData 
  {
    public:
      BSExtraData();
      virtual ~BSExtraData();

      std::uint8_t cEtype;
      BSExtraData* pNext;
  };

  static_assert(sizeof(BSExtraData) == 0xC, "BSExtraData has wrong size");
  
} // namespace CommonLib
