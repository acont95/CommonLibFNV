#pragma once

class Date
{
  public:
    Date();
    ~Date();

    unsigned __int16 sDate;
    unsigned __int16 sYear;
};

static_assert(sizeof(Date) == 0x4, "Date has wrong size");
