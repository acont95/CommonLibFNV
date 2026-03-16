#pragma once

namespace CommonLib {

  class TESTerrainLODManager
  {
    public:
      TESTerrainLODManager();
      ~TESTerrainLODManager();
  };

  static_assert(sizeof(TESTerrainLODManager) == 0x1, "TESTerrainLODManager has wrong size");
    
} // namespace CommonLib
