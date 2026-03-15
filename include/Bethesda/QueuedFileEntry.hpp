#pragma once
#include "Bethesda/BSFileEntry.hpp"
#include "Bethesda/QueuedFile.hpp"

class QueuedFileEntry : QueuedFile
{
  public:
    QueuedFileEntry();
    ~QueuedFileEntry();

    char* pFileName;
    BSFileEntry* pFileEntry;
};

static_assert(sizeof(QueuedFileEntry) == 0x30, "QueuedFileEntry has wrong size");
