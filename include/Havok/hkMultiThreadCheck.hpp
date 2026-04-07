#pragma once
#include <cstdint>

namespace CommonLib {

  class hkMultiThreadCheck
  {
    public:
      hkMultiThreadCheck();
      ~hkMultiThreadCheck();

      enum AccessType : std::int32_t
      {
        HK_ACCESS_IGNORE = 0x0,
        HK_ACCESS_RO = 0x1,
        HK_ACCESS_RW = 0x2,
      };

      enum ReadMode : std::int32_t
      {
        THIS_OBJECT_ONLY = 0x0,
        RECURSIVE = 0x1,
      };

      enum MarkedStatus : std::int32_t
      {
        MARKED_RO = 0xFFFFFFE1,
        MARKED_RO_SELF_ONLY = 0xFFFFFFC1,
        UNMARKED = 0xFFFFFFF1,
      };

      std::uint32_t m_threadId;
      std::uint16_t m_markCount;
      std::uint16_t m_markBitStack;
  };

  static_assert(sizeof(hkMultiThreadCheck) == 0x8, "hkMultiThreadCheck has wrong size");
  
} // namespace CommonLib
