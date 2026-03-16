#pragma once
#include <cstdint>
#include "Types.hpp"
#include "Bethesda/ActorValue.hpp"
#include "Bethesda/TESHealthForm.hpp"
#include "Bethesda/BGSAmmoForm.hpp"
#include "Bethesda/BGSClipRoundsForm.hpp"
#include "Bethesda/BGSRepairItemList.hpp"
#include "Bethesda/BGSEquipType.hpp"
#include "Bethesda/BGSBipedModelList.hpp"
#include "Bethesda/BGSPickupPutdownSounds.hpp"
#include "Bethesda/TESObjectSTAT.hpp"
#include "Bethesda/TESFullName.hpp"
#include "Bethesda/TESScriptableForm.hpp"
#include "Bethesda/TESEnchantableForm.hpp"
#include "Bethesda/TESValueForm.hpp"
#include "Bethesda/TESWeightForm.hpp"
#include "Bethesda/TESAttackDamageForm.hpp"
#include "Bethesda/BGSDestructibleObjectForm.hpp"
#include "Bethesda/BGSPreloadable.hpp"
#include "Bethesda/BGSMessageIcon.hpp"

class BGSProjectile;
class TESObjectIMOD;
class SpellItem;
class TESEffectShader;
class BGSImpactDataSet;

struct OBJ_WEAP_VATS_SPECIAL
{
  SpellItem *pVATSSpecialEffect;
  float fVATSSpecialAP;
  float fVATSSpecialMultiplier;
  float fVATSSkillRequired;
  bool bSilent;
  bool bModRequired;
  std::uint8_t cFlags;
};

class TESObjectWEAP : 
  public TESBoundObject, 
  public TESFullName, 
  public TESModelTextureSwap, 
  public TESIcon, 
  public TESScriptableForm, 
  public TESEnchantableForm, 
  public TESValueForm, 
  public TESWeightForm, 
  public TESHealthForm, 
  public TESAttackDamageForm, 
  public BGSAmmoForm, 
  public BGSClipRoundsForm, 
  public BGSDestructibleObjectForm, 
  public BGSRepairItemList, 
  public BGSEquipType, 
  public BGSPreloadable, 
  public BGSMessageIcon, 
  public BGSBipedModelList, 
  public BGSPickupPutdownSounds 
{
  public:
    TESObjectWEAP();
    virtual ~TESObjectWEAP();

    enum WEAPONHITBEHAVIOR : std::int32_t
    {
      WHB_NORMAL = 0x0,
      WHB_DISMEMBER_ONLY = 0x1,
      WHB_EXPLODE_ONLY = 0x2,
      WHB_NO_DISMEMBER_OR_EXPLODE = 0x3,
    };

    enum WEAPON_RUMBLE_PATTERN : std::int32_t
    {
      RUMBLE_CONSTANT = 0x0,
      RUMBLE_PERIODIC_SQUARE = 0x1,
      RUMBLE_PERIODIC_TRIANGLE = 0x2,
      RUMBLE_PERIODIC_SAWTOOTH = 0x3,
      RUMBLE_PATTERN_COUNT = 0x4,
    };

    enum WEAPON_MOD_EFFECT : std::int32_t
    {
      WEAPON_MOD_NONE = 0x0,
      WEAPON_MOD_INCREASE_WEAPON_DAMAGE = 0x1,
      WEAPON_MOD_INCREASE_CLIP_SIZE = 0x2,
      WEAPON_MOD_DECREASE_SPREAD = 0x3,
      WEAPON_MOD_DECREASE_WEIGHT = 0x4,
      WEAPON_MOD_AMMO_REGEN_SHOT = 0x5,
      WEAPON_MOD_AMMO_REGEN_SECONDS = 0x6,
      WEAPON_MOD_EQUIP_SPEED = 0x7,
      WEAPON_MOD_FIRE_SPEED = 0x8,
      WEAPON_MOD_PROJECTILE_SPEED = 0x9,
      WEAPON_MOD_MAX_HEALTH = 0xA,
      WEAPON_MOD_SILENCE = 0xB,
      WEAPON_MOD_SPLIT_BEAM = 0xC,
      WEAPON_MOD_VATS_BONUS = 0xD,
      WEAPON_MOD_IRON_SITES = 0xE,
      WEAPON_MOD_VATS_SPECIAL_ATTACK = 0xF,
      WEAPON_MOD_EFFECT_COUNT = 0x10,
    };

    struct OBJ_WEAP
    {
      char eType;
      std::uint8_t pad01[3];
      float fSpeed;
      float fReach;
      std::uint8_t cFlags;
      std::uint8_t cHandGripAnim;
      std::uint8_t cAmmoPerShot;
      std::uint8_t cReloadAnim;
      float fMinSpread;
      float fSpread;
      float fDrift;
      float fIronFOV;
      std::uint8_t cConditionLevel;
      std::uint8_t pad02[3];
      BGSProjectile *pProjectile;
      std::uint8_t cVATSToHitChance;
      std::uint8_t cAttackAnim;
      std::uint8_t cNumProjectiles;
      std::uint8_t cEmbeddedConditionValue;
      float fMinRange;
      float fMaxRange;
      WEAPONHITBEHAVIOR eHitBehavior;
      std::uint32_t iFlagsEx;
      float fAttackMult;
      float fShotsPerSec;
      float fActionPoints;
      float fFiringRumbleLeftMotorStrength;
      float fFiringRumbleRightMotorStrength;
      float fFiringRumbleDuration;
      float fDamageToWeaponMult;
      float fAnimShotsPerSecond;
      float fAnimReloadTime;
      float fAnimJamTime;
      float fAimArc;
      ActorValue::Index eSkill;
      WEAPON_RUMBLE_PATTERN eRumblePattern;
      float fRumbleWavelength;
      float fLimbDamageMult;
      ActorValue::Index eResistance;
      float fIronSightUseMult;
      float fSemiAutomaticFireDelayMin;
      float fSemiAutomaticFireDelayMax;
      float fCookTimer;
      WEAPON_MOD_EFFECT eModActionOne;
      WEAPON_MOD_EFFECT eModActionTwo;
      WEAPON_MOD_EFFECT eModActionThree;
      float fModActionOneValue;
      float fModActionTwoValue;
      float fModActionThreeValue;
      std::uint8_t cPowerAttackOverrideAnim;
      std::uint8_t pad03[3];
      std::uint32_t iStrengthRequirement;
      char iModReloadClipAnimation;
      char iModFireAnimation;
      std::uint8_t pad04[2];
      float fAmmoRegenRate;
      float fKillImpulse;
      float fModActionOneValueTwo;
      float fModActionTwoValueTwo;
      float fModActionThreeValueTwo;
      float fKillImpulseDistance;
      std::uint32_t iSkillRequirement;
    };

    struct OBJ_WEAP_CRITICAL
    {
      std::uint16_t sCriticalDamage;
      std::uint8_t pad01[2];
      float fCriticalChanceMult;
      bool bEffectOnDeath;
      std::uint8_t pad02[3];
      SpellItem *pEffect;
    };

    OBJ_WEAP data;
    OBJ_WEAP_CRITICAL criticalData;
    TESModel ShellCasingModel;
    TESModel ScopeModel;
    TESModel WorldModel;
    TESEffectShader *pScopeEffect;
    TESSound *pAttackSound;
    TESSound *pAttackSound2;
    TESSound *pAttackSound2D;
    TESSound *pAttackLoop;
    TESSound *pAttackFailSound;
    TESSound *pMeleeBlockSound;
    TESSound *pIdleSound;
    TESSound *pEquipSound;
    TESSound *pUnEquipSound;
    TESSound *pModSilencedSound;
    TESSound *pModSilencedSound2;
    TESSound *pModSilencedSound2D;
    BGSImpactDataSet *pImpactDataSet;
    TESObjectSTAT *p1stPersonObject;
    TESObjectSTAT *p1stPersonMod1Object;
    TESObjectSTAT *p1stPersonMod2Object;
    TESObjectSTAT *p1stPersonMod3Object;
    TESObjectSTAT *p1stPersonMod12Object;
    TESObjectSTAT *p1stPersonMod23Object;
    TESObjectSTAT *p1stPersonMod13Object;
    TESObjectSTAT *p1stPersonMod123Object;
    TESModelTextureSwap WorldModelMod1;
    TESModelTextureSwap WorldModelMod2;
    TESModelTextureSwap WorldModelMod3;
    TESModelTextureSwap WorldModelMod12;
    TESModelTextureSwap WorldModelMod13;
    TESModelTextureSwap WorldModelMod23;
    TESModelTextureSwap WorldModelMod123;
    TESObjectIMOD *pModObjectOne;
    TESObjectIMOD *pModObjectTwo;
    TESObjectIMOD *pModObjectThree;
    BSStringT<char> EmbeddedWeaponNode;
    SOUND_LEVEL eSoundLevel;
    BSStringT<char> VATSAttackName;
    OBJ_WEAP_VATS_SPECIAL specialVATSData;
    bool bIsLoopingReload;
};

static_assert(sizeof(TESObjectWEAP) == 0x388, "TESObjectWEAP has wrong size");
