#pragma once

namespace CommonLib {

  template <typename T>
  class NiTMallocInterface
  {
    public:
      NiTMallocInterface();
      ~NiTMallocInterface();
  };

  static_assert(sizeof(NiTMallocInterface<void *>) == 0x1, "NiTMallocInterface has wrong size");
  
} // namespace CommonLib
