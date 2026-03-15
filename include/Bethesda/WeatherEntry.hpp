#pragma once
#include <cstdint>
#include "Bethesda/TESWeather.hpp"
#include "Bethesda/TESGlobal.hpp"

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
