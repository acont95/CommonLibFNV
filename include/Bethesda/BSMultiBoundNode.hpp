#pragma once
#include "Bethesda/BSNiNode.hpp"
#include "Gamebryo/NiPointer.hpp"
#include "Bethesda/BSMultiBound.hpp"
#include "Bethesda/BSCullingProcess.hpp"


class BSMultiBoundNode : BSNiNode
{
  public:
    BSMultiBoundNode();
    ~BSMultiBoundNode();

    NiPointer<BSMultiBound> spMultiBound;
    BSCullingProcess::BSCPCullingType CullingMode;
};

static_assert(sizeof(BSMultiBoundNode) == 0xB4, "BSMultiBoundNode has wrong size");
