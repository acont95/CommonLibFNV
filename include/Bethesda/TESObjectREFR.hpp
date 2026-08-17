#pragma once
#include <cstdint>
#include "Bethesda/ExtraDataList.hpp"
#include "Bethesda/TESChildCell.hpp"
#include "Bethesda/TESForm.hpp"
#include "Bethesda/bhkPhantom.hpp"
#include "Gamebryo/NiAVObject.hpp"

namespace CommonLib {

  class TESSound;
  class TESBoundObject;
  class TESObjectCELL;
  class BSSoundHandle;
  class TESTopic;
  class ActorCause;
  class TrapEntry;
  class TargetEntry;
  class BSFaceGenNiNode;
  class BSFaceGenAnimationData;
  class Animation;
  class BipedAnim;
  class BSAnimNoteReceiver;

  class TESObjectREFR : public TESForm, public TESChildCell
  {
    public:

      struct OBJ_REFR
      {
        TESBoundObject* pObjectReference;
        NiPoint3 Angle;
        NiPoint3 Location;
      };

      struct LOADED_REF_DATA
      {
        TESObjectREFR* pCurrentWaterObject;
        std::int32_t iUnderwaterCount;
        float fRelevantWaterHeight;
        float fCachedRadius;
        std::uint32_t iFlags;
        NiPointer<NiAVObject> m_spData3D;
        NiPointer<bhkPhantom> spPhantom;
      };

      virtual bool GetEditorLocation(NiPoint3*, NiPoint3*, TESForm**, TESForm*);
      virtual BSSoundHandle* VoiceSoundFunction(BSSoundHandle*, TESTopic*, Actor*, bool, bool, bool, bool);
      virtual void UpdateSoundCallBack();
      virtual void DamageObject(float, bool);
      virtual bool GetCastShadows();
      virtual void SetCastShadows(bool);
      virtual bool GetMotionBlur();
      virtual void SetMotionBlur(bool);
      virtual bool GetDangerous_2();
      virtual bool GetObstacle_2();
      virtual bool GetQuestObject_2();
      virtual void SetActorCause(ActorCause*);
      virtual ActorCause* GetActorCause();
      virtual NiPoint3* GetStartingAngle(NiPoint3*);
      virtual NiPoint3* GetStartingLocation(NiPoint3*);
      virtual void SetStartingPosition(NiPoint3);
      virtual void UpdateRefLight();
      virtual TESObjectREFR* RemoveItem(TESBoundObject*, ExtraDataList*, int, bool, bool, TESObjectREFR*, const NiPoint3*, const NiPoint3*, bool, bool);
      virtual void RemoveItemType(ENUM_FORM_ID, bool, int);
      virtual bool AddWornItem(TESBoundObject*, int, ExtraDataList*, bool);
      virtual bool RemoveWornItem(TESBoundObject*, int, ExtraDataList*);
      virtual void DoTrap(TrapEntry*, TargetEntry*);
      virtual void AddObjecttoContainer(TESBoundObject*, ExtraDataList*, int);
      virtual NiPoint3* GetLookingAtLocation(NiPoint3*);
      virtual MagicCaster* GetMagicCaster();
      virtual MagicTarget* GetMagicTarget();
      virtual bool IsChild(bool);
      virtual TESActorBase* GetTemplateActorBase();
      virtual void SetTemplateActorBase(TESActorBase*);
      virtual BSFaceGenNiNode* GetFaceNodeBiped(NiNode*);
      virtual BSFaceGenNiNode* GetFaceNodeSkinned(NiNode*);
      virtual BSFaceGenNiNode* GetFaceNode(NiNode*);
      virtual BSFaceGenAnimationData* GetFaceAnimationData(NiNode*);
      virtual bool ClampToGround();
      virtual bool DetachHavok();
      virtual void InitHavok();
      virtual NiAVObject* Load3D(bool);
      virtual void Set3D(NiAVObject*, bool);
      virtual NiAVObject* Get3D();
      virtual bool GetRandomAnim_2();
      virtual NiPoint3* GetBoundMin(NiPoint3*);
      virtual NiPoint3* GetBoundMax(NiPoint3*);
      virtual void UpdateAnimation();
      virtual Animation* GetAnimation();
      virtual BipedAnim* GetBiped();
      virtual BipedAnim* GetCurrentBiped();
      virtual void SetBiped(BipedAnim*);
      virtual const NiPoint3* GetLocationOnReference();
      virtual void SetRunsInLow(bool);
      virtual void MoveHavok(bool);
      virtual void SetActionComplete(bool);
      virtual void SetMovementComplete(bool);
      virtual void ResetInventory(bool);
      virtual NiAVObject* GetFireNode();
      virtual void SetFireNode(NiAVObject*);
      virtual SIT_SLEEP_STATE GetSitSleepState();
      virtual bool IsNpc();
      virtual bool IsCreature();
      virtual bool IsExplosion();
      virtual bool IsProjectile();
      virtual void SetParentCell(TESObjectCELL*);
      virtual bool IsDead(bool);
      virtual bool IsKnockedOut();
      virtual bool IsParalyzed();
      virtual BSAnimNoteReceiver* CreateAnimNoteReceiver();
      virtual BSAnimNoteReceiver* GetAnimNoteReceiever();


      TESSound *pRandomSound;
      OBJ_REFR data;
      float fRefScale;
      TESObjectCELL *pParentCell;
      ExtraDataList m_Extra;
      LOADED_REF_DATA *pLoadedData;
  };

  static_assert(sizeof(TESObjectREFR) == 0x68, "TESObjectREFR has wrong size");
  
} // namespace CommonLib
