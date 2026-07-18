#pragma once
#include "Bethesda/BSAnimNote.hpp"
#include "Gamebryo/NiFixedString.hpp"
#include "Gamebryo/NiTextKeyExtraData.hpp"
#include "Gamebryo/NiStringPalette.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiInterpolator.hpp"
#include "Gamebryo/NiInterpController.hpp"
#include "Gamebryo/NiTimeController.hpp"
#include "Gamebryo/NiStringPalette.hpp"

namespace CommonLib {

  class NiControllerManager;
  class NiAVObject;
  class NiBlendInterpolator;

  class NiControllerSequence : public NiObject
  {
    public:
      virtual ~NiControllerSequence();

      class InterpArrayItem
      {
        NiPointer<NiInterpolator> m_spInterpolator;
        NiPointer<NiInterpController> m_spInterpCtlr;
        NiBlendInterpolator *m_pkBlendInterp;
        unsigned __int8 m_ucBlendIdx;
        unsigned __int8 m_ucPriority;
      };

      class IDTag
      {
        NiFixedString m_kAVObjectName;
        NiFixedString m_kPropertyType;
        NiFixedString m_kCtlrType;
        NiFixedString m_kCtlrID;
        NiFixedString m_kInterpolatorID;
      };

      enum AnimState 
      {
        INACTIVE = 0x0,
        ANIMATING = 0x1,
        EASEIN = 0x2,
        EASEOUT = 0x3,
        TRANSSOURCE = 0x4,
        TRANSDEST = 0x5,
        MORPHSOURCE = 0x6,
      };

      NiFixedString m_kName;
      unsigned int m_uiArraySize;
      unsigned int m_uiArrayGrowBy;
      NiControllerSequence::InterpArrayItem *m_pkInterpArray;
      NiControllerSequence::IDTag *m_pkIDTagArray;
      float m_fSeqWeight;
      NiPointer<NiTextKeyExtraData> m_spTextKeys;
      NiTimeController::CycleType m_eCycleType;
      float m_fFrequency;
      float m_fBeginKeyTime;
      float m_fEndKeyTime;
      float m_fLastTime;
      float m_fWeightedLastTime;
      float m_fLastScaledTime;
      NiControllerManager *m_pkOwner;
      NiControllerSequence::AnimState m_eState;
      float m_fOffset;
      float m_fStartTime;
      float m_fEndTime;
      float m_fDestFrame;
      NiControllerSequence *m_pkPartnerSequence;
      NiFixedString m_kAccumRootName;
      NiAVObject *m_pkAccumRoot;
      NiPointer<NiStringPalette> m_spDeprecatedStringPalette;
      __int16 ssCurAnimNIdx;
      NiPointer<BSAnimNote> *spAnimNotesA;
      unsigned __int16 usNumNotes;
      bool bRemovableObjects;
  };

  static_assert(sizeof(NiControllerSequence) == 0x74, "NiControllerSequence has wrong size");
  
} // namespace CommonLib
