#pragma once
#include "Bethesda/bhkRefObject.hpp"

namespace CommonLib {

  class hkSerializableCinfo;

  class bhkSerializable : public bhkRefObject
  {
    public:
      bhkSerializable();
      ~bhkSerializable();

      hkSerializableCinfo* pInfo;
  };

  static_assert(sizeof(bhkSerializable) == 0x10, "bhkSerializable has wrong size");
  
} // namespace CommonLib
