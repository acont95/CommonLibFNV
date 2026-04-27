#pragma once
#include "Bethesda/QueuedFile.hpp"

namespace CommonLib {

  class BSFileEntry;

  class QueuedFileEntry : public QueuedFile
  {
    public:

      char* pFileName;
      BSFileEntry* pFileEntry;
  };

  static_assert(sizeof(QueuedFileEntry) == 0x30, "QueuedFileEntry has wrong size");
  
} // namespace CommonLib
