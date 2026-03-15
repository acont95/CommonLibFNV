#pragma once

class BSSpinLock
{
  public:
    BSSpinLock();
    ~BSSpinLock();

    volatile unsigned int uiOwningThread;
    unsigned int uiLockCount;
};

static_assert(sizeof(BSSpinLock) == 0x8, "BSSpinLock has wrong size");
