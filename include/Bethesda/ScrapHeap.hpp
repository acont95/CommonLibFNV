#pragma once

class ScrapHeap
{
  public:
    ScrapHeap();
    ~ScrapHeap();

    struct Header
    {
      unsigned int iSize;
      Header *pPrev;
    };

    char *pMemHeap;
    char *pCurrentStackLoc;
    char *pEndHeap;
    Header *pLastBlock;
};

static_assert(sizeof(ScrapHeap) == 0x10, "ScrapHeap has wrong size");
