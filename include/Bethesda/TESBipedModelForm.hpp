#pragma once
#include <cstdint>
#include "Bethesda/BaseFormComponent.hpp"
#include "Bethesda/TESModelTextureSwap.hpp"
#include "Bethesda/TESIcon.hpp"
#include "Bethesda/BGSMessageIcon.hpp"
#include "Bethesda/TESModelRDT.hpp"


namespace CommonLib {

  struct BIPED_MODEL
  {
    std::uint32_t iBipedObjectSlots;
    std::uint8_t sFlags;
  };

  class TESBipedModelForm : public BaseFormComponent 
  {
    public:
      virtual ~TESBipedModelForm();

      BIPED_MODEL bipedModelData;
      TESModelTextureSwap bipedModel[2];
      TESModelTextureSwap worldModel[2];
      TESIcon inventoryIcon[2];
      BGSMessageIcon messageIcon[2];
      TESModelRDT ConstraintTemplate;
  };

  static_assert(sizeof(TESBipedModelForm) == 0xDC, "TESObjectARMO has wrong size");
  
} // namespace CommonLib
