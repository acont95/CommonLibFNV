#pragma once
#include "Bethesda/TESBoundObject.hpp"
#include "Bethesda/TESModelTextureSwap.hpp"
#include "Bethesda/TESScriptableForm.hpp"
#include "Bethesda/TESDescription.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/TESValueForm.hpp"
#include "Bethesda/TESWeightForm.hpp"
#include "Bethesda/BGSDestructibleObjectForm.hpp"
#include "Bethesda/BGSMessageIcon.hpp"
#include "Bethesda/BGSPickupPutdownSounds.hpp"

class TESObjectIMOD :
    public TESBoundObject,
    public TESFullName,
    public TESModelTextureSwap,
    public TESIcon,
    public TESScriptableForm,
    public TESDescription,
    public TESValueForm,
    public TESWeightForm,
    public BGSDestructibleObjectForm,
    public BGSMessageIcon,
    public BGSPickupPutdownSounds
{
  public:
    TESObjectIMOD();
    virtual ~TESObjectIMOD();
};

static_assert(sizeof(TESObjectIMOD) == 0xB0, "TESObjectIMOD has wrong size");
