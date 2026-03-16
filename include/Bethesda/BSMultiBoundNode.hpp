#pragma once
#include "Bethesda/BSNiNode.hpp"
#include "Bethesda/BSMultiBound.hpp"
#include "Bethesda/BSCullingProcess.hpp"


class BSMultiBoundNode : public BSNiNode
{
  public:
    BSMultiBoundNode();
    ~BSMultiBoundNode();

    NiPointer<BSMultiBound> spMultiBound;
    BSCullingProcess::BSCPCullingType CullingMode;
};

static_assert(sizeof(BSMultiBoundNode) == 0xB4, "BSMultiBoundNode has wrong size");
