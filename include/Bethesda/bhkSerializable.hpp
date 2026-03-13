#pragma once
#include "Bethesda/bhkRefObject.hpp"
#include "Havok/hkSerializableCinfo.hpp"

class bhkSerializable : bhkRefObject
{
  public:
    bhkSerializable();
    ~bhkSerializable();

    hkSerializableCinfo* pInfo;
};

static_assert(sizeof(bhkSerializable) == 0x10, "bhkSerializable has wrong size");
