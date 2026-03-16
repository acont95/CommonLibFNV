#pragma once
#include <cstdint>

class TESWeather;
class TESGlobal;

class WeatherEntry
{
  public:
    WeatherEntry();
    ~WeatherEntry();

    TESWeather *pWeather;
    std::uint32_t uiChance;
    TESGlobal *pChanceVar;
};

static_assert(sizeof(WeatherEntry) == 0xC, "WeatherEntry has wrong size");
