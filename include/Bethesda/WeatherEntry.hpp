#pragma once
#include "Bethesda/TESWeather.hpp"
#include "Bethesda/TESGlobal.hpp"

class WeatherEntry
{
  public:
    WeatherEntry();
    ~WeatherEntry();

    TESWeather *pWeather;
    unsigned int uiChance;
    TESGlobal *pChanceVar;
};

static_assert(sizeof(WeatherEntry) == 0xC, "WeatherEntry has wrong size");
