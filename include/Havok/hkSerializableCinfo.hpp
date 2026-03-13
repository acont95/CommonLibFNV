#pragma once

class hkSerializableCinfo
{
  public:
    hkSerializableCinfo();
    ~hkSerializableCinfo();
};

static_assert(sizeof(hkSerializableCinfo) == 0x1, "hkSerializableCinfo has wrong size");
