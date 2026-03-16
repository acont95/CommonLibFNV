#pragma once
#include <cstdint>

namespace CommonLib {

  class TESWaterForm;

  class BGSPlaceableWaterData
  {
    public:
      BGSPlaceableWaterData();
      ~BGSPlaceableWaterData();

      std::uint32_t ulFlags;
      TESWaterForm *pWaterType;
  };

  static_assert(sizeof(BGSPlaceableWaterData) == 0x8, "BGSPlaceableWaterData has wrong size");
  
} // namespace CommonLib
