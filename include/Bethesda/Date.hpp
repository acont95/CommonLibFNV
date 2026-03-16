#pragma once
#include <cstdint>

namespace CommonLib {

  class Date
  {
    public:
      Date();
      ~Date();

      std::uint16_t sDate;
      std::uint16_t sYear;
  };

  static_assert(sizeof(Date) == 0x4, "Date has wrong size");
  
} // namespace CommonLib
