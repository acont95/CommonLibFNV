#pragma once

class BGSListForm;

class BGSRepairItemList
{
  public:
    BGSRepairItemList();
    virtual ~BGSRepairItemList();

    BGSListForm *pListForm;
};

static_assert(sizeof(BGSRepairItemList) == 0x8, "BGSRepairItemList has wrong size");
