#pragma once
#include "Gamebryo/NiRefObject.hpp"

// TODO
namespace CommonLib {

  class ProjectilePickCache : NiRefObject
  {
    public:
      ProjectilePickCache();
      virtual ~ProjectilePickCache();

      char *pCache;
  };

  static_assert(sizeof(ProjectilePickCache) == 0xC, "ProjectilePickCache has wrong size");
  
} // namespace CommonLib
