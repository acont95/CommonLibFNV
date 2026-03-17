#pragma once
#include <cstdint>
#include "Types.hpp"
#include "Bethesda/TESModelPSA.hpp"
#include "Gamebryo/NiPoint3.hpp"

// TO DO
namespace CommonLib {

  class BGSDebris;
  class BGSExplosion;
  class BGSImpactDataSet;

  class PART_DATA
  {
    float fDamageMult;
    unsigned __int8 cFlags;
    unsigned __int8 cType;
    unsigned __int8 cHealthPercent;
    char cActorValue;
    unsigned __int8 cToHitChance;
    unsigned __int8 cExplosionChance;
    unsigned __int8 cExplosionGenericDebrisCount;
    BGSDebris *pExplosionGenericDebris;
    BGSExplosion *pExplosion;
    float fTrackingMaxAngle;
    float fExplosionGenericDebrisScale;
    unsigned __int8 cDismemberGenericDebrisCount;
    BGSDebris *pDismemberGenericDebris;
    BGSExplosion *pDismemberExplosion;
    float fDismemberGenericDebrisScale;
    NiPoint3 kGoreTranslate;
    NiPoint3 kGoreRotate;
    BGSImpactDataSet *pDismemberImpactDataSet;
    BGSImpactDataSet *pExplosionImpactDataSet;
    unsigned __int8 cDismemberDecalCount;
    unsigned __int8 cExplosionDecalCount;
    float fExplosionSpecialDebrisScale;
  };

  class BGSBodyPart 
  {
    public:
      BGSBodyPart();
      virtual ~BGSBodyPart();

      enum LIMB_ENUM
      {
        LIMB_NONE = 0xFFFFFFFF,
        LIMB_TORSO = 0x0,
        LIMB_HEAD_1 = 0x1,
        LIMB_HEAD_2 = 0x2,
        LIMB_LEFT_ARM_1 = 0x3,
        LIMB_LEFT_ARM_2 = 0x4,
        LIMB_RIGHT_ARM_1 = 0x5,
        LIMB_RIGHT_ARM_2 = 0x6,
        LIMB_LEFT_LEG_1 = 0x7,
        LIMB_LEFT_LEG_2 = 0x8,
        LIMB_LEFT_LEG_3 = 0x9,
        LIMB_RIGHT_LEG_1 = 0xA,
        LIMB_RIGHT_LEG_2 = 0xB,
        LIMB_RIGHT_LEG_3 = 0xC,
        LIMB_BRAIN = 0xD,
        LIMB_WEAPON = 0xE,
        LIMB_COUNT = 0xF,
      };

      enum LIMB_CHALLENGE
      {
        CHALLENGE_LIMB_NONE = 0x0,
        CHALLENGE_LIMB_HEAD = 0x1,
        CHALLENGE_LIMB_TORSO = 0x2,
        CHALLENGE_LIMB_LEFT_ARM = 0x3,
        CHALLENGE_LIMB_RIGHT_ARM = 0x4,
        CHALLENGE_LIMB_LEG = 0x5,
        CHALLENGE_LIMB_WEAPON = 0x6,
        CHALLENGE_LIMB_COUNT = 0x7,
      };

      BSStringT<char> NodeName;
      BSStringT<char> TargetName;
      BSStringT<char> IKStartNodeName;
      BSStringT<char> PartName;
      BSStringT<char> GoreObjectName;
      TESModel ExplosionSpecialDebris;
      TESModelPSA PSAModel;
      PART_DATA Data;
  };

  static_assert(sizeof(BGSBodyPart) == 0xB0, "BGSBodyPart has wrong size");
  
} // namespace CommonLib
