#pragma once
#include <cstdint>

namespace CommonLib {

  class ScrapHeap
  {
    public:
      ScrapHeap();
      ~ScrapHeap();

      struct Header
      {
        std::uint32_t iSize;
        Header *pPrev;
      };

      char *pMemHeap;
      char *pCurrentStackLoc;
      char *pEndHeap;
      Header *pLastBlock;
  };

  static_assert(sizeof(ScrapHeap) == 0x10, "ScrapHeap has wrong size");
  
} // namespace CommonLib
