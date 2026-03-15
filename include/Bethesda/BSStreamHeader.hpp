#pragma once

class BSStreamHeader
{
  public:
    BSStreamHeader();
    ~BSStreamHeader();
    
    unsigned int uiVersion;
    char pAuthor[64];
    char pProcessScript[64];
    char pExportScript[64];
};

static_assert(sizeof(BSStreamHeader) == 0xC4, "BSStreamHeader has wrong size");
