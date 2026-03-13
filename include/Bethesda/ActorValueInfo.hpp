#pragma once
#include "Bethesda/TESForm.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/TESDescription.hpp"
#include "Bethesda/TESIcon.hpp"
#include "Bethesda/ActorValue.hpp"
#include "Bethesda/BSStringT.hpp"
#include "Bethesda/ActorValueOwner.hpp"

class ActorValueInfo : TESForm, TESFullName, TESDescription, TESIcon
{
  public:
    ActorValueInfo();
    ~ActorValueInfo();

    char* sScriptName;
    BSStringT<char> sAbbreviation;
    unsigned int uFlags;
    ActorValue::Section eAVType;
    float (__cdecl *pDerivationFunction)(ActorValueOwner*, ActorValue::Index);
    ActorValue::Index (__cdecl *pMappingFunction)(ActorValueOwner*, ActorValue::Index);
    void (__cdecl *pModifiedCallback)(ActorValueOwner *, ActorValue::Index, float, float, ActorValueOwner *);
    int iNumDependentActorValues;
    ActorValue::Index DependentActorValues[15];
    int iEnumCount;
    char *sEnumNames[10];
};

static_assert(sizeof(ActorValueInfo) == 0xC4, "ActorValueInfo has wrong size");
