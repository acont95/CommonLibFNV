#pragma once
#include "Gamebryo/NiTPrimitiveArray.hpp"
#include "Bethesda/BSAnimNote.hpp"

namespace CommonLib {

  class IBSAnimNoteReceiver;

  class BSAnimNoteListener
  {
    public:

      class BSAnimReceiverType
      {
        BSAnimNote::AnimNoteType eNoteType;
        IBSAnimNoteReceiver *pReceiver;
      };

      NiTPrimitiveArray<BSAnimReceiverType *> ReceiverA;
  };

  static_assert(sizeof(BSAnimNoteListener) == 0x10, "BSAnimNoteListener has wrong size");
  
} // namespace CommonLib
