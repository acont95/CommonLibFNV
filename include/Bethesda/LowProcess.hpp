#pragma once
#include <cstdint>
#include "Types.hpp"
#include "Bethesda/BaseProcess.hpp"
#include "Bethesda/BSSimpleList.hpp"
#include "Bethesda/ModifierList.hpp"
#include "Bethesda/CombatTimer.hpp"

namespace CommonLib {

  class TESBoundObject;
  class TESObjectREFR;
  class BGSListForm;
  class ObjectstoAcquire;
  class TESFaction;
  class GuardActorPackageData;

  class LowProcess : public BaseProcess
  {
    public:
      virtual void ProcessEscort(Actor*);
      virtual void ProcessSleep(Actor*);
      virtual void ProcessEat(Actor*, TESObjectREFR*);
      virtual void ProcessCombat(Actor*);
      virtual void ProcessAlarm(Actor*);
      virtual bool ProcessActivate(Actor*, bool);
      virtual void ProcessAccompany(Actor*);
      virtual void ProcessAcquire(Actor*);
      virtual void ProcessAmbushWait(Actor*);
      virtual bool ProcessUseItemAt(Actor*);
      virtual bool ProcessUseWeapon(Actor*);
      virtual void ProcessChooseSpell(Actor*);
      virtual void ProcessFleeNonCombat(Actor*);
      virtual void ProcessAvoidArea(Actor*);
      virtual void ProcessSandBox(Actor*);
      virtual void ProcessMovementBlocked(Actor*);
      virtual void ProcessGuard(Actor*);
      virtual void ProcessGuardStartTravelToLocation(Actor*, GuardActorPackageData*);
      virtual void ProcessPatrol(Actor*);
      virtual void ProcessSummonCreatureDefend(Actor*);
      virtual void ProcessClearMountPosition(Actor*);
      virtual void ProcessNotify(Actor*);
      virtual bool CheckIfHasObject(Actor*, std::int32_t);
      virtual TESObjectREFR* GetTargetForPackage(Actor*, TESPackage*);
      virtual TESObjectREFR* GetLocationForPackage(Actor*, TESPackage*, bool);
      virtual void EvaluateOrderAcquireList(Actor*);

      std::uint8_t m_uFlags;
      TESBoundObject *pItemBeingUsed;
      CombatTimer fCombatDelayTimer;
      TESObjectREFR *const pTarget;
      TESObjectREFR *pGenericLocation;
      TESObjectREFR *pGenericSecondLocation;
      BGSListForm *pTargetFormList;
      std::int16_t sFormListNumb;
      TESObjectREFR *pPatrolLocation;
      int iNumberItemsActivate;
      BSSimpleList<ObjectstoAcquire *> ObjectList;
      ObjectstoAcquire *pAcquireObject;
      ObjectstoAcquire *pSavedAcquireObject;
      BSSimpleList<TESObjectREFR *> GenericLocationsList;
      BSSimpleList<ObjectstoAcquire *> TempObjectList;
      BSSimpleList<TESObjectREFR *> TempLocList;
      TESBoundObject *pObjecttoAcquire;
      TESBoundObject *pObjectForLocation;
      PACKAGE_OBJECT_TYPE eFormType;
      TESFaction *pFactiontoAquire;
      ModifierList pDamageModifiers;
      float fEssentialDownTimer;
      float fDeathTime;
      float fTrackedDamage;
      bool bSkippedTimeStampForPathing;
  };

  static_assert(sizeof(LowProcess) == 0xB4, "LowProcess has wrong size");
  
} // namespace CommonLib
