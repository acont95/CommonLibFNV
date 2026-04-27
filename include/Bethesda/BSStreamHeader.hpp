#pragma once
#include <cstdint>

namespace CommonLib {

  class BSStreamHeader
  {
    public:

      std::uint32_t uiVersion;
      char pAuthor[64];
      char pProcessScript[64];
      char pExportScript[64];
  };

  static_assert(sizeof(BSStreamHeader) == 0xC4, "BSStreamHeader has wrong size");
  
} // namespace CommonLib
