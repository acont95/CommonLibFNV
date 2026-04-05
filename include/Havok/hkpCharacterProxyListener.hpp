#pragma once

namespace CommonLib {

  class hkpCharacterProxyListener
  {
    public:
      hkpCharacterProxyListener();
      virtual ~hkpCharacterProxyListener();
  };

  static_assert(sizeof(hkpCharacterProxyListener) == 0x4, "hkpCharacterProxyListener has wrong size");
  
} // namespace CommonLib
