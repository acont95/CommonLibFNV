#pragma once
#include "Gamebryo/NiTObjectArray.hpp"
#include "Gamebryo/NiTPrimitiveSet.hpp"
#include "Gamebryo/NiTStringPointerMap.hpp"
#include "Gamebryo/NiTObjectSet.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Gamebryo/NiAVObjectPalette.hpp"
#include "Gamebryo/NiTimeController.hpp"
#include "Bethesda/BSAnimNoteListener.hpp"

namespace CommonLib {

  class NiControllerSequence;

  class NiControllerManager : public NiTimeController
  {
    public:

      NiTObjectArray<NiPointer<NiControllerSequence> > m_kSequenceArray;
      NiTPrimitiveSet<NiControllerSequence *> m_kActiveSequences;
      NiTStringPointerMap<NiControllerSequence *> m_kStringMap;
      BSAnimNoteListener *pListener;
      bool m_bCumulative;
      NiTObjectSet<NiPointer<NiControllerSequence> > m_kTempBlendSeqs;
      NiPointer<NiAVObjectPalette> m_spObjectPalette;
  };

  static_assert(sizeof(NiControllerManager) == 0x7C, "NiControllerManager has wrong size");
  
} // namespace CommonLib
