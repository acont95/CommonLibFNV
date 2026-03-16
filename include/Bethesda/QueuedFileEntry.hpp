#pragma once
#include "Bethesda/QueuedFile.hpp"

class BSFileEntry;

class QueuedFileEntry : public QueuedFile
{
  public:
    QueuedFileEntry();
    ~QueuedFileEntry();

    char* pFileName;
    BSFileEntry* pFileEntry;
};

static_assert(sizeof(QueuedFileEntry) == 0x30, "QueuedFileEntry has wrong size");
