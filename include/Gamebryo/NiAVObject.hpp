#pragma once
#include "Gamebryo/NiNode.hpp"
#include "Gamebryo/NiObjectNET.hpp"
#include "Gamebryo/NiTPointerList.hpp"
#include "Gamebryo/NiCollisionObject.hpp"
#include "Gamebryo/NiProperty.hpp"
#include "Gamebryo/NiTransform.hpp"
#include "Bethesda/BSNiBound.hpp"

class NiAVObject : NiObjectNET {
  public:
    NiAVObject();
    virtual ~NiAVObject();

    NiNode* m_pkParent;
    NiPointer<NiCollisionObject> m_spCollisionObject;
    BSNiBound* m_kWorldBound;
    NiTPointerList<NiPointer<NiProperty>> m_kPropertyList;
    unsigned int m_uFlags;
    NiTransform m_kLocal;
    NiTransform m_kWorld;
};

static_assert(sizeof(NiAVObject) == 0x9C, "NiAVObject has wrong size");
