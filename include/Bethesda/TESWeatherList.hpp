#pragma once
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/WeatherEntry.hpp"

class TESWeatherList : BSSimpleList<WeatherEntry*>
{
  public:
    TESWeatherList();
    ~TESWeatherList();
};

static_assert(sizeof(TESWeatherList) == 0x8, "TESWeatherList has wrong size");
