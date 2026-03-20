#pragma once
#include <cstdint>
#include "Bethesda/Character.hpp"
#include "Bethesda/BSSoundHandle.hpp"
#include "Bethesda/TeleportPath.hpp"
#include "Bethesda/TESRegionList.hpp"
#include "Bethesda/bhkRigidBody.hpp"
#include "Bethesda/ActorValue.hpp"
#include "Bethesda/bhkMouseSpringAction.hpp"
#include "Bethesda/GamePlayFormulas.hpp"
#include "Bethesda/CharacterProgression.hpp"
#include "Gamebryo/NiTMap.hpp"
#include "Gamebryo/NiLight.hpp"

namespace CommonLib {

  class TESObjectWEAP;
  class DialoguePackage;
  class ImageSpaceModifierInstanceDOF;
  class MagicItem;
  class ActiveEffect;
  class TESWorldSpace;
  class TESObjectCELL;
  class TESObjectREFR;
  class BGSNote;
  class ImageSpaceModifierInstanceDRB;
  class MagicTarget;
  class CameraCaster;
  class HitCaster;
  class TESBoundObject;
  class PlayerActionObject;
  class CasinoData;
  class TESCaravanCard;
  class BipedAnim;
  class Animation;
  class MagicShaderHitEffect;
  template <typename T>
  class NiTPrimitiveArray;
  class TESTopic;
  class TESQuestStageItem;
  class Actor;
  class BGSQuestObjective;
  class TESQuestTarget;
  class TESQuest;
  class TESObjectBOOK;
  class TESClass;
  class AlchemyItem;
  class TESForm;
  class CombatGroup;
  class ItemChange;
  class TESAmmo;
  class TESReputation;
  class AudioMarkerInfo;
  class TESRegion;
  class TESRegionSound;
  class BGSMusicType;
  class ActorsNearPlayerData;
  class PerkRankData;
  class BGSPerkEntry;
  class MapMarkerData;

  class PLAYER_TARGET_LOC
  {
    public:
      TESWorldSpace *pWorld;
      TESObjectCELL *pInterior;
      NiPoint3 Location;
      NiPoint3 Angle;
      bool bResetWeather;
      void (__cdecl *pfnArrivalFunc)(std::int32_t);
      std::int32_t iArrivalFuncData;
      TESObjectREFR *pFurnitureRef;
      TESObjectREFR *pFastTravelMarker;
  };

  struct AchievementInstance
  {
    bool bUnlocked;
    std::int32_t iCurrentValue;
    bool bTracking;
  };

  enum KILL_CAM_TYPE
  {
    KILL_CAM_NONE = 0x0,
    KILL_CAM_PLAYER = 0x1,
    KILL_CAM_VATS = 0x2,
  };

  struct MAP_MARKER_STRUCT
  {
    MapMarkerData *pData;
    TESObjectREFR *pRef;
  };

  class PlayerCharacter : Character
  {
    public:
      PlayerCharacter();
      virtual ~PlayerCharacter();

      enum ModifierGroup
      {
        TEMPORARY = 0x0,
        SCRIPTS = 0x1,
        DAMAGE = 0x2,
      };

      enum PROGRESS_EVENT 
      {
        LEVEL_UP = 0x0,
        DEATH = 0x1,
        EVENT_COUNT = 0x2,
      };

      enum DISABLE_PLAYER_CONTROLS 
      {
        DPC_NONE = 0x0,
        DPC_MOVEMENT = 0x1,
        DPC_LOOKING = 0x2,
        DPC_PIPBOY = 0x4,
        DPC_FIGHTING = 0x8,
        DPC_POV_SWITCH = 0x10,
        DPC_ROLL_OVER = 0x20,
        DPC_SNEAKING = 0x40,
        DPC_COUNT = 0x7,
        DPC_ALL = 0xFF,
      };

      enum GrabbingType
      {
        GRAB_NONE = 0x0,
        GRAB_NORMAL = 0x1,
        GRAB_INVENTORY_DROP = 0x2,
        GRAB_TELEKINESIS = 0x3,
      };

      enum TerminalAccessType 
      {
        TAT_HAS_NOTE = 0x0,
        TAT_HACKED = 0x1,
        TAT_LOCKED = 0x2,
        TAT_HACK_ELIGIBLE = 0x3,
        TAT_HACK_INELIGIBLE = 0x4,
      };

      AchievementInstance PlayerAchievements[3];
      PLAYER_TARGET_LOC *pQueuedTargetLoc;
      TESObjectWEAP *pQueuedWeaponAttach;
      float fTimeSinceLastAmmoRegenTick;
      char cShotsSinceLastAmmoRegen;
      std::int32_t iSandmanDetection;
      std::int32_t iCombatPersue;
      bool bTravelUseDoor;
      bool bOnElevator;
      bool bForceQuestTargetUpdate;
      DialoguePackage *pClosestConversation;
      bool btransporting;
      BSSimpleList<ActiveEffect *> *pActiveEffectList;
      MagicItem *pCurrentSpell;
      MagicTarget *pDesiredTarget;
      CameraCaster *pCameraCaster;
      HitCaster *pHitCaster;
      DialoguePackage *pAIConversationRunning;
      std::int32_t iNumberofStealWarnings;
      float fStealWarningTimer;
      std::int32_t iNumberofPickpocketWarnings;
      float fPickPocketWarningTimer;
      BSSimpleList<MagicItem *> *EatDrinkItems;
      BSSimpleList<TESBoundObject *> *QueuedWornEnchantments;
      bool bShowQuestItemsInInventory;
      float TemporaryActorValueModifiers[77];
      float ScriptActorValueModifiers[77];
      float fHealthModifier;
      float DamageActorValueModifiers[77];
      BSSimpleList<BGSNote *> listNotes;
      ImageSpaceModifierInstanceDOF *pIronsightsDOFInstance;
      ImageSpaceModifierInstanceDOF *pVatsDOFInstance;
      ImageSpaceModifierInstanceDRB *pVatsDRBInstance;
      bool bHostileDetection;
      bool bIsAcousticSpaceTransition;
      BSSimpleList<Actor *> pListOfTeammates;
      TESObjectREFR *pLastExtDoorActivated;
      bool bSpeaking;
      BSSimpleList<PlayerActionObject *> *pListofActions;
      BSSimpleList<CasinoData *> *pListofCasinoData;
      BSSimpleList<TESCaravanCard *> *pInactiveListofCaravanCards;
      BSSimpleList<TESCaravanCard *> *pActiveListofCaravanCards;
      std::uint32_t iCaravanCapWinnings;
      std::uint32_t iCaravanCapLosses;
      std::uint32_t iCaravanWinnings;
      std::uint32_t iCaravanLosses;
      std::uint32_t iCaravanLargestWinning;
      std::uint32_t iCasinoCheatLevel;
      NiPointer<bhkMouseSpringAction> spGrabSpring;
      TESObjectREFR *pGrabbedObject;
      PlayerCharacter::GrabbingType eGrabType;
      float fGrabObjectWeight;
      float fGrabDistance;
      bool bsave3rdPerson;
      bool b3rdPersonSaved;
      bool b3rdPerson;
      bool bActually3rdPerson;
      bool bWant3rdPerson;
      bool bTemp3rdPerson;
      bool bTemp3rdPersonSwitchBack;
      bool bTemp1stPerson;
      bool bTemp1stPersonSwitchBack;
      bool bAlwaysRun;
      bool bAutoMove;
      std::int32_t iSleepTime;
      bool bIsSleeping;
      float fFOV;
      float fsecondRunning;
      float fsecondSwimming;
      float fsecondSneaking;
      bool bActorinSneakRange;
      bool bCanFastTravel;
      bool bCanWait;
      float fWorldFOV;
      float f1stPersonFOV;
      float f3rdPersonFOV;
      std::int32_t iNumberTraining;
      std::uint8_t ucControlsDisabled;
      bool bBlockActivate;
      float fBlockActivateTimer;
      TESObjectREFR *pForceActivateRef;
      BipedAnim *p1stPersonBipedAnim;
      Animation *p1stPersonAnimation;
      NiPointer<NiAVObject> sp1stPerson3D;
      float fEyeHeight;
      NiPointer<NiNode> spInventoryPC;
      Animation *pInventoryAnimation;
      MagicShaderHitEffect *pInventoryWeaponEffect;
      BSSimpleList<TESTopic *> listTopics;
      BSSimpleList<TESQuestStageItem *> listQuestLog;
      TESQuest *pActiveQuest;
      BSSimpleList<BGSQuestObjective *> listObjectives;
      BSSimpleList<TESQuestTarget *> listQuestTargets;
      bool bGreetingPlayer;
      float fGreetTimer;
      std::int32_t ihourstosleep;
      char cMurder;
      std::int32_t iAmountStolenSold;
      float fSortActorDistanceTimer;
      float fSitHeadingDelta;
      bool bBeenAttacked;
      MagicItem *pSelectedSpell;
      TESObjectBOOK *pSelectedScroll;
      TESObjectREFR *pPlayerMapMarker;
      TeleportPath PlayerMarkerPath;
      float fProjectileReleaseTimer;
      std::int32_t iNumAdvance;
      ActorValue::Index eskilladvance;
      TESClass *pDefaultClass;
      TESClass *pClassBasedOn;
      std::uint32_t pCrimeCounts[5];
      AlchemyItem *pPendingPoison;
      bool bChargen;
      bool bAllowEGMCacheClear;
      bool bTelekinesisSelected;
      TESRegion *pOccupiedRegion;
      TESRegionList m_AllOccupiedRegions;
      BSSimpleList<TESRegionSound *> CurrentRegionSoundList;
      BSSoundHandle StatusSoundHandle;
      void *pInitialStateBuffer;
      std::uint32_t iLastPlayingTimeUpdate;
      std::uint32_t iTotalPlayingTime;
      std::uint32_t iCharacterSeed;
      bool bAiControlledToPos;
      bool bAiControlledFromPos;
      bool bAiControlledActivate;
      bool bAiControlledPackage;
      bool bInBorderContainedCell;
      bool bReturnToLastKnownGoodPosition;
      NiPoint3 LastKnownGoodPosition;
      TESForm *pLastKnownGoodLocation;
      NiTPrimitiveArray<TESRegion *> *pBorderRegions;
      BGSMusicType *pLastKnownMusicType;
      GamePlayFormulas::DifficultyLevel eDifficultyLevel;
      GamePlayFormulas::HardcoreSetting eHardcoreSetting;
      KILL_CAM_TYPE eKillCameraSetting;
      bool bBeingChased;
      bool bIsYoung;
      bool bIsToddler;
      bool bCanUsePowerArmor;
      BSSimpleList<MAP_MARKER_STRUCT *> MapMarkerList;
      TESWorldSpace *pMapWorld;
      BSSimpleList<AudioMarkerInfo *> AudioMarkerList;
      AudioMarkerInfo *pClosestAudioMarkerInfo;
      float fUFOCameraHeading;
      float fUFOCameraPitch;
      NiPoint3 UFOCameraPos;
      std::uint32_t iSelectedSpellCastSoundID;
      BSSoundHandle SelectedSpellCastSound;
      BSSoundHandle MagicFailureSounds[6];
      BSSimpleList<TESObjectREFR *> DroppedRefList;
      NiTMap<std::uint32_t,unsigned char> RandomDoorSpaceMap;
      NiPointer<NiLight> sp1stPersonLight;
      NiPointer<NiLight> sp3rdPersonLight;
      bool bInsufficientChargeMessageShown;
      float fDropAngleMod;
      float fLastDropAngleMod;
      CharacterProgression CharacterProgressionInfo;
      BSSimpleList<PerkRankData *> Perks;
      BSSimpleList<BGSPerkEntry *> PerkEntryLists[74];
      BSSimpleList<PerkRankData *> CompanionPerks;
      BSSimpleList<BGSPerkEntry *> CompanionPerkEntryLists[74];
      Actor *pAutoAimActor;
      NiPoint3 BulletAutoAim;
      NiPointer<NiAVObject> spTargeted3D;
      bool bTarget3DDistant;
      Actor *pPlayersTargetActor;
      BSSimpleList<ActorsNearPlayerData *> *pListofPercievedActors;
      float fMenuModeButtonTimer;
      float fAmmoSwapButtonTimer;
      bool bMenuModeButtonClicked;
      NiPoint3 kCamera3rdPersonShoulderOffset;
      CombatGroup *pCombatGroup;
      std::uint32_t iTeammateCount;
      float fCombatTimer;
      float fYieldTimer;
      NiAVObject *pWobbleNodes[2][12];
      NiPoint3 Cached1stPersonCameraPos;
      NiPoint3 CachedWorldCameraPos;
      NiPointer<bhkRigidBody> spCameraRigidBody;
      bool bPlayerInCombat;
      bool bAllCombatTargetsSearching;
      bool bMegatonDestroyed;
      BSSimpleArray<ItemChange *,1024> RockItLauncherAmmoList;
      float fRockItLauncherAmmoWeight;
      bool bNightVisionOn;
      TESReputation *pReputationUpdate;
      unsigned __int8 cSloMoCameraHits;
      float fTimeSinceLastAttack;
      float fTimeInSlowMoCam;
      float fKillCamCooldown;
      bool bIgnoresGTM;
      bool bTurboISM;
      float fLastHelloTime;
      float fCounterAttackTimer;
      bool bCounterAttackCamera;
      bool bHasCateyeActive;
      bool bHasSpotterActive;
      float fCheckForItems;
      NiAVObject *m_pWeaponSightingNode;
      bool bAlwaysHardcore;
      bool bResetHardcoreTimers;
      BSSimpleArray<TESAmmo *,1024> HotKeyLastAmmo;
      TESQuest* pPatch04DebugQuest; // Credit yUI-NVSE
  };

  static_assert(sizeof(PlayerCharacter) == 0xE50, "PlayerCharacter has wrong size");
  
} // namespace CommonLib
