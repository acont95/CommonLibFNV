#pragma once
#include "Bethesda/BSSimpleList.hpp"

namespace CommonLib {

  class WeatherEntry;

  class TESWeatherList : public BSSimpleList<WeatherEntry*>
  {
    public:
      TESWeatherList();
      ~TESWeatherList();
  };

  static_assert(sizeof(TESWeatherList) == 0x8, "TESWeatherList has wrong size");
  
} // namespace CommonLib
