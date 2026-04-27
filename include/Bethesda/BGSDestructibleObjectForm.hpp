#pragma once
#include "Bethesda/BaseFormComponent.hpp"

namespace CommonLib {

  class DestructibleObjectData;

  class BGSDestructibleObjectForm : public BaseFormComponent
  {
    public:

      DestructibleObjectData *pData;
  };

  static_assert(sizeof(BGSDestructibleObjectForm) == 0x8);

} // namespace CommonLib
