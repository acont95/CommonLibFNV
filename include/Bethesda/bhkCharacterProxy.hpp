#pragma once
#include "Bethesda/bhkSerializable.hpp"
#include "Bethesda/bhkCharacterPointCollector.hpp"

namespace CommonLib {

  class bhkCharacterController;

  class bhkCharacterProxy : public bhkSerializable
  {
    public:
      bhkCharacterProxy();
      virtual ~bhkCharacterProxy();
      
      bhkCharacterPointCollector m_ignoredCollisionStartCollector;
  };

  static_assert(sizeof(bhkCharacterProxy) == 0x3E0, "bhkCharacterProxy has wrong size");
  
} // namespace CommonLib
