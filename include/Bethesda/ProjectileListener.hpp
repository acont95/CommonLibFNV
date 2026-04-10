#pragma once
#include "Bethesda/bhkCharacterController.hpp"
#include "Bethesda/Projectile.hpp"

namespace CommonLib {

  class ProjectileListener  : bhkCharacterController
  {
    public:
      ProjectileListener ();
      virtual ~ProjectileListener ();

      Projectile *pProj;
  };

  static_assert(sizeof(ProjectileListener) == 0x660, "ProjectileListener  has wrong size");
  
} // namespace CommonLib
