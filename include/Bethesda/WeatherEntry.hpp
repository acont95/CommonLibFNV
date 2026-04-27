#pragma once
#include <cstdint>

namespace CommonLib {

  class TESWeather;
  class TESGlobal;

  class WeatherEntry
  {
    public:

      TESWeather *pWeather;
      std::uint32_t uiChance;
      TESGlobal *pChanceVar;
  };

  static_assert(sizeof(WeatherEntry) == 0xC, "WeatherEntry has wrong size");
  
} // namespace CommonLib
